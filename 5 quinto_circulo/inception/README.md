*This project has been created as part of the 42 curriculum by rmanzana*

# Inception

## Description

This project sets up a multi-container Docker Compose stack inside a Linux VM, designed to deploy a secure web infrastructure where each component runs in its own isolated container.

The stack consists of three main services:
- `mariadb` — Relational database engine
- `wordpress` — Web application powered by dedicated PHP-FPM
- `nginx` — Sole HTTPS entry point and TLS termination

## Project description

### Docker usage
The project is assembled with `srcs/docker-compose.yml`. Each service has a custom Dockerfile in `srcs/requirements/`, so the images are built locally instead of pulled from Docker Hub.

Included sources:
- `srcs/docker-compose.yml`
- `srcs/requirements/mariadb/Dockerfile`
- `srcs/requirements/wordpress/Dockerfile`
- `srcs/requirements/nginx/Dockerfile`
- Config files and setup scripts in `srcs/requirements/*/conf` and `srcs/requirements/*/tools`

The stack uses Docker named volumes for persistent data, a `.env` file for configuration, and Docker secrets for sensitive passwords.

### Design choices
- Docker Compose is used because the subject requires one container per service and a multi-service stack.
- Named volumes are used for the WordPress database and website files, with the host data path honoring the required `/home/rmanzana/data` layout.
- Secrets are generated automatically during `make` by `srcs/requirements/tools/generate_secrets.sh`.
- A bridge network is used so containers can talk to each other safely, since `host` network mode and `links` are forbidden.
- Nginx is the only public-facing container and serves HTTPS on port `443` (by default) with TLSv1.2/1.3.

### Comparisons
- Virtual Machines vs Docker
  - A virtual machine is like a full-size restaurant with its own kitchen staff and recipes.
  - Docker is like a cook in the host kitchen: you give it recipes, and it uses the ingredients and resources already there.

 So a VM is heavier and more isolated, while Docker is lighter and shares the host system. Multiple Docker containers can run on the same host.
- Secrets vs Environment Variables
  - Environment variables in `.env` are used for normal configuration, like paths and names.
  - Docker secrets are used for passwords and other confidential values.
- Docker Network vs Host Network
  - Docker Compose uses a bridge network so the containers can talk to each other privately and resolve service names. Host networking is forbidden here because it bypasses Docker isolation and exposes services directly on the VM host network.
- Docker Volumes vs Bind Mounts
  - Docker named volumes are the required persistence method for this project. They let Docker manage the storage while still keeping the data available to the containers, and they are configured so the data lives under the required host path (/home/login/data). Bind mounts are not allowed.

## Instructions

### Prerequisites
- A Linux VM prepared for the project
- Docker and Docker Compose v2 installed in the VM
- Bash shell available in the VM
- Permission to run Docker commands with `sudo` or by being in the `docker` group

### Setup
1. Create or verify `srcs/.env` contains the required environment variables.
2. Build and start the stack:
   - `make`
   - `make` also generates the missing Docker secret files in `secrets/` before building and starting the containers.
3. Stop the stack:
   - `make down`

### Useful commands
- Start attached: `make attached`
- Stop containers: `make down`
- Remove unused images: `make clean`
- Remove all volumes and data: `make fclean`
- List Docker containers: `make ls-cnt`
- List Docker volumes: `make ls-vols`
- Show available host IPs: `make ip`
- View container logs: `make logs_<container>` (e.g. `make logs_nginx`)
- Open a shell in a container: `make shell_<container>` (e.g. `make shell_mariadb`)

## Resources

### 1. WordPress Automation & PHP-FPM
- **WP-CLI Official Handbook:** https://make.wordpress.org/cli/handbook/
  - Essential for automating WordPress installation, database connection, and user creation (`wp config create`, `wp core install`) directly from bash scripts without a web browser.
- **PHP-FPM Configuration Docs:** https://www.php.net/manual/en/install.fpm.configuration.php
  - Technical reference for modifying `www.conf` to configure FastCGI to listen on TCP port 9000 (`listen = 9000`) instead of UNIX sockets.

### 2. MariaDB & Volume Initialization
- **MariaDB `mariadb-install-db` Tool:** https://mariadb.com/kb/en/mariadb-install-db/
  - Official guide on initializing the `/var/lib/mysql` data directory securely from scratch on an empty Docker volume without systemd.
- **MariaDB `--init-file` Parameter:** https://mariadb.com/kb/en/mysqld-options/#-init-file
  - How to pass a `.sql` initialization script at startup to automate `CREATE DATABASE`, user privileges, and root password setup.

### 3. Nginx Reverse Proxy & SSL/TLS
- **Nginx FastCGI Example (Official Wiki):** https://www.nginx.com/resources/wiki/start/topics/examples/phpfcgi/
  - The exact architecture required to configure the `location ~ \.php$` block using `fastcgi_pass wordpress:9000;` to avoid 502 Bad Gateway errors.
- **Nginx Pitfalls and Common Mistakes:** https://nginx.org/en/docs/http/pitfalls.html
  - What to avoid in Nginx configuration files (like bad `if` statements and deprecated directives) to ensure clean, standard-compliant code.
- **OpenSSL Certificate Request Manual:** https://www.openssl.org/docs/manmaster/man1/openssl-req.html
  - Complete reference for generating non-interactive, self-signed SSL/TLS certificates using `-x509`, `-nodes`, and `-subj` flags inside Dockerfiles or scripts.

### 4. Docker Architecture & PID 1 Management
- **Docker Best Practices (ENTRYPOINT vs CMD):** https://docs.docker.com/reference/dockerfile/#entrypoint
  - Technical breakdown of exec-form vs shell-form, explaining how to properly pass `SIGTERM` signals using `exec "$@"` in entrypoint scripts.
- **Understanding PID 1 and Zombie Processes in Linux:** https://github.com/krallin/tini#why-tini
  - Clear architectural explanation of how process management works inside container namespaces and why running foreground daemons (`daemon off;`) is mandatory.

### 5. AI-Assisted Research
- **Google NotebookLM:** Used to summarize and clarify official documentation and tutorials.

### AI usage
Besides NotebookLM I also used AI as a supplementary reference tool throughout the development of this project. Specifically, it assisted me with:

- **Concept Verification:** Clarifying core Docker, Linux, and networking principles encountered during my research.
- **Documentation & Approaches:** Quickly navigating documentation, comparing architectural options, and finding starting points for complex topics.
- **Debugging:** Helping identify and troubleshoot configuration syntax and runtime errors.
- **Proofreading:** Fixing grammar, phrasing, and typos in the Markdown documentation files.
- **Decision Making** Helped me weigh architectural choices, such as whether to generate Docker secrets at build time or keep them pre-created somewhere else.

## Glossary
- **PHP-FPM (FastCGI Process Manager):** An alternative PHP FastCGI implementation that manages background worker processes to handle web application logic.
- **TLS (Transport Layer Security):** The cryptographic protocol used by Nginx to encrypt HTTP traffic (HTTPS).