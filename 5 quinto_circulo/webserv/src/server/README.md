# Server Module - Network Engine

## Overview
This module implements the **core network engine** of the web server. It is responsible for managing all TCP connections, handling asynchronous I/O using `poll()`, and coordinating the communication between clients and the HTTP handler. The design follows a **non-blocking, event-driven architecture** inspired by Nginx.

---

## 🛠 Architecture & Data Flow

### Core Components
- **`Server`**: The main class that owns the event loop, socket management, and client lifecycle.
- **`Client`**: Represents a single TCP connection with its request buffer and response file descriptor.
- **`HttpHandler`**: External component (implemented by a teammate) that processes HTTP requests and generates responses.

### Data Flow Diagram
```
[Network] → [poll()] → [Event Detected]
                              │
                    ┌─────────┴─────────┐
                    │                   │
               POLLIN              POLLOUT
                    │                   │
            readFromClient()     sendToClient()
                    │                   │
            Request Buffer      Read from responseFd
                    │                   │
            \r\n\r\n found?       Send to socket
                    │
            HttpHandler.handleRequest()
                    │
            client.setResponseFd(fd)
```

### The Contract with HttpHandler
The Server module communicates with the HTTP handler through a **minimal interface**:

| Server provides | HttpHandler provides |
|----------------|---------------------|
| `Client::getRequestBuffer()` - Raw HTTP request | `Client::setResponseFd(int fd)` - FD with full response |
| `Client::getConfig()` - Server configuration | The FD contains: headers + body (complete HTTP response) |

> **Key Design Decision**: The response FD contains the **entire HTTP response** (headers + body). The Server's `sendToClient()` simply reads from this FD and sends to the socket. This unifies handling of static files and CGI.

---

## 📦 Class Reference

### Client Class

#### Member Variables
| Variable | Type | Default | Description |
|----------|------|---------|-------------|
| `_fd` | `int` | `-1` | Client socket file descriptor |
| `_lastActivity` | `time_t` | `time(NULL)` | Timestamp for timeout detection |
| `_requestBuffer` | `std::string` | empty | Accumulated HTTP request data |
| `_responseFd` | `int` | `-1` | FD with complete HTTP response |
| `_config` | `const ServerConfig*` | `NULL` | Pointer to associated server config |

#### Main Methods
| Method | Description |
|--------|-------------|
| `appendRequest(data, size)` | Appends received data to request buffer |
| `setResponseFd(fd)` | Sets the FD for response (called by HttpHandler) |
| `hasResponse()` | Returns `true` if `_responseFd >= 0` |
| `clearRequest()` | Clears request buffer (for keep-alive) |
| `getResponseFd()` | Returns the FD to read response from |
| `getRequestBuffer()` | Returns the accumulated request data |

### Server Class

#### Member Variables
| Variable | Type | Description |
|----------|------|-------------|
| `_allServers` | `std::vector<ServerConfig>` | Parsed server configurations from config parser |
| `_fds` | `std::vector<struct pollfd>` | File descriptors monitored by poll() |
| `_listenFds` | `std::vector<int>` | Listening socket FDs |
| `_clients` | `std::map<int, Client>` | Active client connections (fd → Client) |

#### Main Methods
| Method | Description |
|--------|-------------|
| `setupSockets()` | Creates, binds and listens on all configured sockets |
| `acceptNewConnection(fd)` | Accepts new TCP connection on listening fd |
| `readFromClient(fd)` | Reads data from socket, detects complete requests |
| `sendToClient(fd)` | Sends response from FD to client socket |
| `isListening(fd)` | Checks if fd is a listening socket |
| `kickClient(fd)` | Removes client, closes fds and cleans resources |
| `setClientEvents(fd, events)` | Updates poll events for a client fd |
| `checkTimeouts()` | Removes clients that exceeded IDLE_TIMEOUT |
| `cleanup()` | Closes all fds and clears vectors |
| `run()` | Main event loop |

---

## 🔄 Event Loop Details

### The poll() Cycle
```
1. checkTimeouts() - Remove stale connections
2. poll(fds, nfds, POLL_TIMEOUT) - Wait for events
3. For each fd with events:
   ├── Listening FD → acceptNewConnection()
   ├── Error/EOF   → kickClient()
   ├── POLLIN      → readFromClient()
   └── POLLOUT     → sendToClient()
```

### Client Lifecycle
```
Client created on accept()
    │
    ▼
readFromClient() accumulates data in _requestBuffer
    │
    ▼
\r\n\r\n detected → Request is complete
    │
    ▼
HttpHandler::handleRequest(client) is called
    │
    ▼
handler calls client.setResponseFd(fd) with response
    │
    ▼
if client.hasResponse() → events changed to POLLOUT
    │
    ▼
sendToClient() reads from responseFd and sends to socket
    │
    ▼
When read() returns 0 → Response fully sent
    │
    ├── Keep-alive → clearRequest(), events back to POLLIN
    └── Close      → kickClient()
```

### Event Transition Examples
```cpp
// After reading complete request with response ready
setClientEvents(fd, POLLOUT);  // Switch to write mode

// After sending complete response
setClientEvents(fd, POLLIN);   // Switch back to read mode (keep-alive)
```

---

## ⚙️ Configuration & Constants

### Server Constants (defined in `Server.hpp`)
| Constant | Value | Description |
|----------|-------|-------------|
| `POLL_TIMEOUT` | `1000` ms | poll() timeout period |
| `IDLE_TIMEOUT` | `30000` ms (30s) | Max idle time before client kick |
| `READ_TIMEOUT` | `5000` ms | Max time for complex reads |
| `KEEP_TIMEOUT` | `15000` ms | Keep-alive timeout |
| `READ_BUFFER` | `4096` bytes | Buffer size for recv() and read() |

---

## 📝 Technical Details

### Non-blocking I/O
All sockets are set to non-blocking mode using `fcntl(fd, F_SETFL, O_NONBLOCK)`. This ensures:
- `accept()` never blocks the event loop
- `recv()` and `send()` return immediately with `EAGAIN` if not ready
- Single-threaded efficiency with many concurrent connections

### Memory Management
- **Request buffer**: Grows dynamically up to `client_max_body_size`
- **Response buffer**: No buffer needed - reads directly from FD in 4KB chunks
- **No full buffering**: Data flows from FD → 4KB buffer → socket without storing entire response in RAM

### Error Handling
- **Socket errors**: `POLLERR`, `POLLHUP`, `POLLNVAL` → immediate `kickClient()`
- **EAGAIN/EWOULDBLOCK**: Non-fatal, retry on next poll cycle
- **Connection close**: `recv()` returns 0 → clean client removal
- **Timeout**: `checkTimeouts()` removes clients inactive for `IDLE_TIMEOUT`

### Keep-Alive Support
After sending a complete response, the server:
1. Closes the response FD
2. Clears the request buffer with `clearRequest()`
3. Sets events back to `POLLIN` via `setClientEvents()`
4. Waits for the next request on the same connection

---

## 🔌 Integration with HttpHandler

### What the Server Expects
```cpp
class HttpHandler {
public:
    /**
     * @brief Process a complete HTTP request
     * @param client Reference to the client with request data
     * 
     * The handler must:
     * 1. Parse client.getRequestBuffer()
     * 2. Determine response (static file or CGI)
     * 3. Create FD with complete HTTP response (headers + body)
     * 4. Call client.setResponseFd(fd)
     */
    void handleRequest(Client& client);
};
```

### The Response FD Contract
The file descriptor set by `HttpHandler` via `client.setResponseFd(fd)` must contain the complete HTTP response:

```
HTTP/1.1 200 OK\r\n
Content-Type: text/html\r\n
Content-Length: 1234\r\n
\r\n
<html>...body content...</html>
```

**FD sources:**
- **Static files**: FD pointing directly to the file on disk
- **CGI scripts**: FD from `pipe()` after script execution
- **Error pages**: FD with error page content

---

## 🐛 Debug Mode Output

When compiled with `make debug`, the server provides detailed logging:

```text
[DEBUG] Server created using config file
[DEBUG-SERVER] Socket config failed.

--- [SERVER] listening on ---
-IP/HOST: 127.0.0.1
-PORT: 8080
-SERVER NAME(S):
    localhost

[92m-New client-
fd: 6
    IP:127.0.0.1
    PORT: 54321[0m

[DEBUG] Received 45 bytes from fd 6
[DEBUG] Request complete for fd 6
[DEBUG] Response set for fd 6 (headers: 156 bytes, body_fd: 7)
[DEBUG] Sent 4096 bytes to fd 6
[DEBUG] Response fully sent to fd 6
[DEBUG] client with fd '6' was kicked.
```

---

## ✅ Features Summary

- [x] Non-blocking I/O with poll()
- [x] Multiple server blocks (virtual hosts)
- [x] Client timeout detection and cleanup
- [x] Keep-alive connections support
- [x] Configurable max body size
- [x] Debug logging mode
- [x] Memory-efficient streaming (no full response buffering)
- [x] Clean resource management on disconnect
- [x] Error handling for all socket operations (EAGAIN, EPIPE, etc.)

---

## 📁 File Structure
```
src/server/
    Server.cpp      # Main server logic & event loop
    Server.hpp      # Server class declaration
    Client.cpp      # Client state management
    Client.hpp      # Client class declaration

inc/server/
    Server.hpp      # Public header
    Client.hpp      # Public header

handler/            # (External - implemented by teammate)
    HttpHandler.hpp # Handler interface
```

---
*For detailed source code comments, refer to the files in `src/server/` directory.*