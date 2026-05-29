*This project has been created as part of the 42 curriculum by rmanzana, pmorello, jaacosta.*

# Webserver

Description
-----------
- This is a small C++ webserver made by three 42 students as a learning project. 

- The goal was to implement a basic HTTP server that can serve static files, 
  run simple CGI scripts (PHP/Python), and handle uploads for specific locations 
  with a configuration parser inspired by Nginx.

- The server is designed to be robust, validating all settings during the parsing phase to ensure
  stable execution.

Instructions
------------
Compilation:
```bash
- make
# For a debug build with symbols and `DEBUG` enabled:
- make debug
```
Run:
```bash
# Example: run with the CGI test config
- ./webserver conf/CGItest.conf
# Press Ctrl+C to stop the server (or use `kill` if backgrounded).
```
- Quick test (from the server machine)
```bash
- curl -v -H "Host: cgitest.local:8080" http://127.0.0.1:8080/
```

Notes:
- Config files are in the `conf/` folder. Set `host` to `0.0.0.0` to listen on all interfaces.
- Use the `www/` folder for site content (see provided examples: `CGItest`, `simpleHTML`).

Resources
---------
- HTTP basics: MDN Web Docs — HTTP Overview: https://developer.mozilla.org/en-US/docs/Web/HTTP/Overview.
- CGI reference: CGI Programming/FAQ (w3.org archives) and PHP CGI docs: https://www.php.net/manual/en/install.fpm.php.
- Sockets and POSIX: Beejs Guide to Network Programming, and Unix Network Programming by W. Richard Stevens.
- Poll/select: Linux `poll(2)` manual and related tutorials.
- GeeksforGeeks: for standard explanation about coding in C++.

How AI was used
----------------
We used AI (mainly Gemini) to help with debugging and refactoring tasks during development.
AI was used for code suggestions, writing small patches, and proposing debugging steps; all final edits and merges were reviewed and applied by the team.


Additional notes
----------------
- This server uses C++98 and POSIX APIs (sockets, `poll`, `fork`/`execve` for CGI).
- It's single-threaded and uses a simple event loop — expect limitations under load.
- We use a vector<uint8_t> cause we use image and for that we must use some type of variable that can read in binari, if our webserver just implemented text, we could use a simple std::string.

## Features

- [x] **HTTP Methods:** Fully supports `GET`, `POST`, and `DELETE` requests.
- [x] **I/O Multiplexing:** Non-blocking I/O using `poll()` (with a single-threaded event loop).
- [x] **CGI Execution:** Handles dynamic scripts (Python, PHP) based on file extensions.
- [x] **File Uploads:** Supports native file uploads via `POST` requests for specific routes.
- [x] **Custom Error Pages:** Configurable default error pages (404, 500, etc.).
- [x] **Directory Listing:** Optional auto-index feature to browse directories from the browser.

## Architecture & Code Structure

The project is structured into modular components, following an object-oriented approach in C++98:

```text
├── conf/					# Configuration files (.conf)
├── www/					# Website root directories and static files
└── src/					# Source code.
	├── main.cpp				# Entry point (initializes the server cluster)
	├── CGI /
		└── CGIHandler.cpp		# Handles fork, environment variables, and execution of scripts
	├── Mime /
		└── MimeTypes.cpp		# Maps file extension to theu corresponing media type
	├── Parser /
		├── ConfigParser.cpp		# Parses the main configuration file, validating syntax and tokens
		├── LocationConfig.cpp		# Holds specific configuration rules for specific URI path/routes
		├── RequestParser.cpp		# Logic that processes and deserializes raw incoming network strings into a valid request
		└── ServerConfig.cpp		# Data structure that stores the parsed configuration for a single virtual server	
	├── Request /
		└── HTTPRequest.cpp		# Parses raw HTTP request strings into usable components
	├──	Response /
		├── HTTPresponse.cpp		# Encapsulates the HTTP network strings into structured objects
		└── ResponseBuilder.cpp		# Generates HTTP status codes, headers, and body payloads
	├── Server /
		├── Server.cpp			# Represents a single server configuration and socket
		└── Client.cpp			# Holds client-specific connection state and buffers
	└── Utils /
		├── BuilderUtils.cpp		# Auxiliary functions used exclusively during HTTP response construction
		├── CGIUtils.cpp		# Helper functions for setting up CGI environments and path resolution
		├── Debug.cpp			# Logging utilities and formatted console printing for development
		├── HTTPStatus.cpp		# Maps standard HTTP numeric codes to their official reason phrases
		└── Utils.cpp			# Generic helper functions

```
