ARG OS_NAME
ARG OS_VERSION

FROM ${OS_NAME}:${OS_VERSION}

# upgrade repos, then install ONLY --no-install-recomends means exactly what is needed to run
# mariadb-server -> the server itself
# mariadb-client -> needed for all the interactions with the database from the yml file like creating tables, adding users...

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y --no-install-recommends \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/lib/mysql /run/mysqld \
    &&chown -R mysql:mysql /var/lib/mysql /run/mysqld \
    && chmod +rwx /run/mysqld

COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

ENTRYPOINT ["/usr/local/bin/setup.sh"]