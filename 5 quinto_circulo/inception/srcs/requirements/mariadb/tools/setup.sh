#!/bin/bash


# COLORS
RED='\033[1;31m'
YELLOW='\033[1;33m'
GREEN='\033[1;32m'
CYAN='\033[1;36m'
RESET='\033[0m'


# VALIDATE SECRETS
# set them if they exist (and not empty), fail if they don't
for var in MYSQL_ROOT_PASSWORD_FILE MYSQL_PASSWORD_FILE; do
    eval f="\$$var"
    [ -n "$f" ] || { echo -e "\t${RED}ERROR: $var not defined at .env${RESET}"; exit 1;}
    [ -s "$f" ] || { echo -e "\t${RED}ERROR: $f not defined or is empty${RESET}"; exit 1;}
done

DB_ROOT_PASS=$(cat "$MYSQL_ROOT_PASSWORD_FILE")
DB_PASS=$(cat "$MYSQL_PASSWORD_FILE")

# CHECK PERSISTENCE & INSTALL DB SYSTEM TABLES
# For some reason /var/lib/mysql/mysql (the file everybody checks for previous mariadb installation)
# is being created so it always skips... then I am creating my own file so I make sure I can control
# and make sure if the database is created by me or just creates some "default" database

if [ ! -f "/var/lib/mysql/.initialized" ]; then
    echo -e "\t${CYAN}Initializing database for first time...${RESET}"
    # I remove whatever default items
    rm -rf /var/lib/mysql/*
    chown -R mysql:mysql /var/lib/mysql
    # INSTALL DB SYSTEM TABLES
    mysql_install_db --user=mysql --datadir=/var/lib/mysql --skip-test-db

    # CONFIGURE DB (USER/DATABASE)
    # create DB, create user, set password, flush privileges...
    echo -e "\t${YELLOW}Creating user and database...${RESET}"
    tfile=$(mktemp)
    trap 'rm -f "$tfile"' EXIT

    cat << EOF > "$tfile"
USE mysql;
FLUSH PRIVILEGES;
-- Deleting some defaults
DELETE FROM mysql.user WHERE User='';
DROP DATABASE IF EXISTS test;

-- Creating database (backticks to prevent problems with SQL reserved words)
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET $MYSQL_CHARSET COLLATE $MYSQL_COLLATION;
    
-- Creating user and autorization
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$DB_PASS';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';

-- Fixing root access
ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASS';

FLUSH PRIVILEGES;
EOF

    mysqld --user=mysql --bootstrap < "$tfile"

    # Create the initialized mark
    touch /var/lib/mysql/.initialized
     echo -e "\t${GREEN}Database created successfully!${RESET}"
else
    echo -e "\t${GREEN}Database detected, skiping creation${RESET}"

fi

# EXECUTE MYSQLD
# Launch mysql server in foreground (PID 1) so container stays alive.

exec mysqld_safe --user=mysql --bind-address=0.0.0.0