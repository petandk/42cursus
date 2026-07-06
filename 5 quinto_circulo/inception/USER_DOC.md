*This project has been created as part of the 42 curriculum by rmanzana*

# User Documentation

This document explains how to start, stop, and use the stack I built for the Inception project.

## Start and stop the stack

From the repository root, use the Makefile:
- Start the stack in detached mode: `make`
- Start the stack in attached mode: `make attached` (runs in foreground, showing live container logs until Ctrl+C) 
- Stop the stack: `make down`

## Access the website

After startup, open the site in your browser at the URL set in `srcs/.env` under `WP_URL`.

This project serves the site over HTTPS only on the configured port (defined in `.env` and `nginx.conf`) through the `nginx` container.

## Access the WordPress admin panel

Open the admin area at:
- `https://login.42.fr/wp-admin`

The admin username is set by `WP_ADMIN_LOGIN` in `srcs/.env`. The admin password is stored in `secrets/wp_admin_pass.secret` and loaded as a Docker secret.

## Manage credentials

Credentials are generated and stored as Docker secrets in the repository root `secrets/` folder:
- `secrets/db_root_pass.secret`
- `secrets/db_pass.secret`
- `secrets/wp_admin_pass.secret`
- `secrets/wp_user_pass.secret`

The `.env` file in `srcs/.env` stores non-sensitive configuration values such as the database host and site URL. If the secret files are missing, running `make` will create them before starting the stack.

### Environment template
```
PROJECT_NAME=

# ------------ server info ------------
DOMAIN_NAME=
USERNAME=
HTTPS_PORT=

# ------------ OS info ------------
OS_NAME=
OS_VERSION=

# ------------ Mariadb config ------------
MYSQL_HOST=
MYSQL_DATABASE=
MYSQL_USER=
MYSQL_CHARSET=
MYSQL_COLLATION=

# ------------ Mariadb secrets ------------
MYSQL_ROOT_PASSWORD_FILE=
MYSQL_PASSWORD_FILE=

# ------------ wordpress config ------------
PHP_VERSION=
WP_URL=
WP_TITLE=
WP_THEME=

# ------------ wordpress ADMIN ------------
WP_ADMIN_LOGIN=
WP_ADMIN_EMAIL=

# ------------ wordpress USER ------------
WP_USER_LOGIN=
WP_USER_EMAIL=

# ------------ wordpress secrets ------------
WP_ADMIN_PASSWORD_FILE=
WP_USER_PASSWORD_FILE=
```

## Basic checks

Check the stack status and logs:
- `docker compose -f srcs/docker-compose.yml ps`
- `docker logs mariadb`
- `docker logs wordpress`
- `docker logs nginx`

Check the persistent data locations on the host:
- `ls -la ${HOME}/data/mariadb`
- `ls -la ${HOME}/data/wordpress`

Check the Docker network:
- `docker network inspect inception_priv_lan`

### Access the MariaDB database

Inside the `mariadb` container, connect as root with this:
```
mariadb -u root -p -h localhost
```
The password is stored in `secrets/db_root_pass.secret`
then
```
USE wordpress;
SHOW TABLES;
or
SHOW TABLES FROM wordpress;
```

## Troubleshooting

If the stack does not start:
- Make sure `srcs/.env` exists and contains valid values
- If the secret files are missing, run `make` again so they are generated automatically
- Inspect container logs with `docker logs <container>`
- Confirm Docker is running inside the VM and your user can run Docker commands

