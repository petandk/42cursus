*This project has been created as part of the 42 curriculum by rmanzana*

# Developer Documentation

This document describes how I set up the Inception stack and how to run it during development.

## Prerequisites

- A Linux VM prepared for the project
- Docker Engine installed inside the VM
- Docker Compose v2 available via `docker compose`
- Bash shell inside the VM
- Optional: add your VM user to the `docker` group so `sudo` is not required

## Repository layout

Root files:
- `Makefile` — commands to build, start, stop, and clean the project
- `README.md` — project overview and instructions
- `USER_DOC.md` — end-user instructions
- `DEV_DOC.md` — developer-focused guide

Service files:
- `srcs/docker-compose.yml` — Docker Compose stack definition
- `srcs/.env` — environment variables used by the services
- `srcs/requirements/mariadb` — MariaDB Dockerfile, config, setup scripts
- `srcs/requirements/wordpress` — WordPress Dockerfile, config, setup scripts
- `srcs/requirements/nginx` — Nginx Dockerfile, config, setup scripts

## Setup

1. Create or verify `srcs/.env` contains the required environment values. (there's a template on the [USER_DOC.md](USER_DOC.md#environment-template))
2. Run `make` from the repository root to prepare host folders, generate any missing secrets, and start the stack.

## Makefile usage

- `make` — build and start the stack in detached mode
- `make attached` — build and start the stack in the foreground
- `make down` — stop and remove containers
- `make clean` — stop containers and remove unused images
- `make fclean` — stop containers and remove volumes and host data under `${HOME}/data`. It also removes `secrets` folder.
- `make ls-vols` — list Docker volumes
- `make ls-cnt` — list Docker containers
- `make ip` — show available host IP addresses
- `make logs_<container_name>` — Shows logs for the specified container.
- `make shell_<container_name>` — Opens an interactive shell inside the specified container.

### Useful Docker commands

- Access a container shell:
  - `docker exec -it <container> bash`
- View container logs:
  - `docker logs <container>`
  - `docker logs -f <container>` (follow mode)
- List running containers:
  - `docker ps`
  - `docker ps -a` (includes stopped ones)
- List images:
  - `docker images`
- List volumes:
  - `docker volume ls`
- Inspect network:
  - `docker network inspect inception_priv_lan`
- Remove unused data:
  - `docker system prune -af`
  - `docker system prune -af --volumes` (also removes volumes)
  
## Docker Compose commands

The stack can also be managed directly with Compose:
- Start:
  - `docker compose -f srcs/docker-compose.yml up --build -d`
- Stop:
  - `docker compose -f srcs/docker-compose.yml down`
- Rebuild a single service:
  - `docker compose -f srcs/docker-compose.yml build <service>`
- View logs:
  - `docker compose -f srcs/docker-compose.yml logs -f`


## Data persistence

The project uses Docker named volumes and stores their data under the host path required by the subject:
- `mariadb-data` → `${HOME}/data/mariadb`
- `wp-data` → `${HOME}/data/wordpress`

Docker secrets are used for credentials and are loaded from the repository root `secrets/` folder.

## Notes for developers

- The WordPress service is built with PHP-FPM only, and Nginx is the only public entry point.
- The Nginx container listens on the configured port (defined in `.env` and `nginx.conf`) with TLSv1.2/1.3 only.
- The project uses a bridge network named `inception_priv_lan` for container communication.
- The secret generation script is `srcs/requirements/tools/generate_secrets.sh`.
- Service names in Docker Compose match the required image names: `mariadb`, `wordpress`, `nginx`.

