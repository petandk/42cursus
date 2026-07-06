#!/bin/bash

# COLORS
RED='\033[1;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
CYAN='\033[1;36m'
RESET='\033[0m'

# VALIDATE SECRETS
# set them if they exist (and not empty), fail if they don't
for var in WP_ADMIN_PASSWORD_FILE WP_USER_PASSWORD_FILE MYSQL_PASSWORD_FILE; do
    eval f="\$$var"
    [ -n "$f" ] || { echo -e "\t${RED}ERROR: $var not defined at .env${RESET}"; exit 1;}
    [ -s "$f" ] || { echo -e "\t${RED}ERROR: $f not defined or is empty${RESET}"; exit 1;}
done

WP_ADMIN_PASS=$(cat "$WP_ADMIN_PASSWORD_FILE")
WP_USER_PASS=$(cat "$WP_USER_PASSWORD_FILE")
SQL_PASS=$(cat "$MYSQL_PASSWORD_FILE")

# WAIT FOR MARIADB
# keep trying until Mariadb is ready to accept queries

spin=('-' '\' '|' '/')
i=0
while ! mariadb -h"$MYSQL_HOST" -u"$MYSQL_USER" -p"$SQL_PASS" "$MYSQL_DATABASE" -e"SELECT 1" &>/dev/null; do
        echo -ne "\r\t${CYAN}${spin[$((i % 4))]} Waiting for MariaDB ${spin[$((i % 4))]} ${RESET}"
	((i++))
	sleep 0.1
done
echo -e "\n\t${GREEN}MariaDB is ready!${RESET}"

# DOWNLOAD WORDPRESS CORE
# download WP files if not present (check for /var/www/html/wp-includes/version.php)

if [ ! -f /var/www/html/wp-includes/version.php ]; then
    echo -e "\t${YELLOW}Downloading WordPress...${RESET}"
    wp core download --allow-root --path=/var/www/html
fi

# CREATE WP-CONFIG.PHP (SKIP IF EXISTS)
# generate config file that tells WP how to connect with mariadb

if [ -f wp-config.php ]; then
	echo -e "\t${GREEN}Wordpress config already created, skipping creation${RESET}"
else
	wp config create --allow-root \
	       --dbname="$MYSQL_DATABASE" \
	       --dbuser="$MYSQL_USER" \
	       --dbpass="$SQL_PASS" \
	       --dbhost="$MYSQL_HOST"
	echo -e "\t${CYAN} Wordpress config created${RESET}"
fi

# wp core neds the port if is different from 443
# but adding it directly on WP_URL messes with the rest
# so I add it here if needed.

if [ "$HTTPS_PORT" = "443" ]; then
	URL="$WP_URL";
else
	URL="$WP_URL":"$HTTPS_PORT";
fi

# INSTALL WORDPRESS CORE (SKIP IF ALREADY INSTALLED)
# creates db tables, sets title, URL, admin user...

if wp core is-installed --allow-root; then
	echo -e "\t${GREEN}WordPress core arleady installed, skipping...${RESET}"
else
	wp core install --allow-root \
		--url="$URL" \
		--title="$WP_TITLE" \
		--admin_user="$WP_ADMIN_LOGIN" \
		--admin_email="$WP_ADMIN_EMAIL" \
		--admin_password="$WP_ADMIN_PASS"
	echo -e "\t${CYAN}WordPress core successfully installed!${RESET}"
fi

# CREATE SECONDARY "AUTHOR" USER
# create a non-admin user with author role (required by project)

if wp user exists "$WP_USER_LOGIN" --allow-root; then
	echo -e "\t${GREEN}User $WP_USER_LOGIN already exists, skipping${RESET}"
else
	wp user create --allow-root "$WP_USER_LOGIN" "$WP_USER_EMAIL" \
		--role=author \
		--user_pass="$WP_USER_PASS"
	echo -e "\t${CYAN}User $WP_USER_LOGIN created!${RESET}"
fi

# INSTALL AND ACTIVATE THEME

if wp theme is-installed "$WP_THEME" --allow-root; then
    echo -e "\t${GREEN}Theme $WP_THEME already installed, skipping...${RESET}"
else
    echo -e "\t${YELLOW}Downloading and activating $WP_THEME theme...${RESET}"
    wp theme install "$WP_THEME" --activate --allow-root
    echo -e "\t${CYAN}Theme $WP_THEME successfully installed and activated!${RESET}"
    
    # Remove default themes to save disk space
    echo -e "\t${YELLOW}Cleaning up default themes...${RESET}"
    wp theme delete twentytwentyfive twentytwentyfour --allow-root 2>/dev/null || true
fi

# LAUNCH PHP-FPM
# start PHP-FPM in foreground so container stays alive and handles signals

echo -e "\t${GREEN}Starting PHP-FPM...${RESET}"
exec "php-fpm${PHP_VERSION}" -F