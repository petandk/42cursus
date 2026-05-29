# webserv

## Overview
This project implements a high-performance web server in **C++98** with a configuration parser inspired by Nginx. The server is designed to be robust, validating all settings during the parsing phase to ensure stable execution.

---

## 🛠 Default Values & Inheritance

To simplify configuration, the parser assigns default values to several directives if they are not specified in the `.conf` file. 

### ⚠️ Important: `host` vs `listen`
In standard Nginx, the `listen` directive often combines both IP and Port (e.g., `listen 127.0.0.1:8080;`). In this project, for better clarity and parsing control, they have been **separated into two distinct directives**:
*   **`host`**: Defines the network interface (IP address).
*   **`listen`**: Defines the port number only.

### Table of Defaults
| Directive                | Context   | Default Value         | Inheritance/Notes                                  |
|--------------------------|-----------|----------------------|----------------------------------------------------|
| **`host`**               | server    | `0.0.0.0`            | Listens on all interfaces if not set               |
| **`listen`**             | server    | `8080`               | Default port (Separated from host)                 |
| `root`                   | server    | `./var/www/html`     | Inherited by location if not explicitly set        |
| `index`                  | server    | `index.html`         | Inherited by location if not explicitly set        |
| `client_max_body_size`   | server    | `1048576` (1 MB)     | Prevents oversized payload attacks                 |
| `server_name`            | server    | `localhost`          | Primary server identifier                          |
| `allowed_methods`        | location  | `GET`                | Restricted to GET by default for security          |
| `autoindex`              | location  | `off`                | Directory listing is disabled by default           |
| `return`                 | location  | `0`                  | No redirection unless specified                    |

---

## 📄 Configuration Example (`conf/Default.conf`)

The server uses a block-based syntax. Note the independent definition of `host` and `listen`:

```nginx
server {
    listen 8080;
    host 127.0.0.1;
    server_name localhost;
    client_max_body_size 1048576;

    error_page 404 /errors/404.html;
    error_page 500 /errors/500.html;

    location / {
        root ./var/www/html;
        index index.html;
        allowed_methods GET POST;
        autoindex off;
    }

    location /uploads {
        root ./var/www/uploads;
        allowed_methods GET POST DELETE;
        upload_path ./var/www/uploads;
        autoindex on;
    }

    location /forbidden {
        return 404;
    }

    location /cgi-bin {
        root ./var/www/cgi-bin;
        allowed_methods GET POST;
        cgi_extension .py;
        cgi_pass /usr/bin/python3;
    }
}
```

---

## 🚀 Build & Run Instructions

### Compilation
*   **Release mode:** `make`
*   **Debug mode:** `make debug` (Enables verbose parsing logs and token traces)

### Execution
*   **Default:** `./webserver` (Uses `conf/Default.conf` automatically)
*   **Custom:** `./webserver path/to/your_config.conf`

### Cleanup
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and the executable.
*   `make re`: Rebuilds the entire project from scratch.

---

## ⚙️ Technical Internals

### How the Parser Works
1.  **Preprocessing:** Strips comments (`#`) and normalizes whitespace for cleaner tokenization.
2.  **Tokenization:** Splits the file into logical units: keywords, values, and control symbols (`{`, `}`, `;`).
3.  **Parsing:** Implements a recursive descent-like approach to build `ServerConfig` and `LocationConfig` objects.
4.  **Validation:** Performs strict checks on syntax, port ranges, and path accessibility. If an error is detected, the server prints a clear diagnostic message and aborts the startup.

### Main Classes
- **`ConfigParser`**: The core engine that handles file I/O, tokenization, and orchestration of the parsing logic.
- **`ServerConfig`**: Container for server-level directives (host, port, error pages).
- **`LocationConfig`**: Container for route-specific logic, including CGI, upload paths, and redirection codes.

### Debug Mode Output
When running in `make debug` mode, the parser provides a detailed, comprehensive trace of the internal state, tokenization, and final parsed objects:

```text
No config file specified, using default configuration.
[DEBUG] Tokens after tokenization:
  [0]: 'server'
  [1]: '{'
  ...
[DEBUG] Calling parseServerBlock. Current token: 'server'
[DEBUG] Entering parseServerBlock
[DEBUG] Entering parseLocationBlock. Current token: 'location'
[DEBUG] Location added to server
...
=== Data after parsing ===
=== Server 0 ===
Host: 127.0.0.1
Ports: 8080
Server Names: localhost
Client max body size: 1048576
Error pages:
  404 -> /errors/404.html
  500 -> /errors/500.html
 --- Location 0 ---
  Path: /
  Root: ./var/www/html
  Index files: index.html
  Allowed methods: GET, POST
  Autoindex: off
  CGI extension: 
  CGI pass: 
  Redirection code: 0
  Redirect URL: 
 --- Location 1 ---
  Path: /uploads
  Root: ./var/www/uploads
  Index files: 
  Allowed methods: GET, POST, DELETE
  Upload path: ./var/www/uploads
  Autoindex: on
  CGI extension: 
  CGI pass: 
  Redirection code: 0
  Redirect URL: 
 --- Location 2 ---
  Path: /forbidden
  Root: 
  Index files: 
  Allowed methods: 
  Upload path: 
  Autoindex: off
  CGI extension: 
  CGI pass: 
  Redirection code: 404
  Redirect URL: 
 --- Location 3 ---
  Path: /cgi-bin
  Root: ./var/www/cgi-bin
  Index files: 
  Allowed methods: GET, POST
  Upload path: 
  Autoindex: off
  CGI extension: .py
  CGI pass: /usr/bin/python3
  Redirection code: 0
  Redirect URL: 
```

---
*For further information, please refer to the source code comments in the `src/config/` directory.*