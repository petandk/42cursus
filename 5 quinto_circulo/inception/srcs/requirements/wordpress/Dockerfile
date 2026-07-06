ARG OS_NAME
ARG OS_VERSION

FROM ${OS_NAME}:${OS_VERSION}

#OS_VERSION gets deleted after FROM so we have to declare it again

ARG OS_VERSION
ARG PHP_VERSION

# Since OS_VERSION can change before I finish this exercice 
# and I've chosen to hardcode a package version, I've dedided
# to protect my Dockerfile so if I change it, it reminds me
# I also have to check the hardcoded version just in case.

RUN if [ "$OS_VERSION" != "bookworm-slim" ]; then \
        echo "OS_VERSION changed, check php version path (www.conf) for newer version (actually 8.2)"; \
        exit 1; \
    fi

# upgrade repos, then install ONLY --no-install-recomends means exactly what is needed to run

RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y --no-install-recommends \
    php-fpm \
    php-mysql \
    php-curl \
    php-imagick \
    php-intl \
    php-json \
    php-mbstring \
    php-xml \
    php-zip \
    mariadb-client \
    curl \
    wget \
    unzip \
    ca-certificates \
    && rm -rf /var/lib/apt/lists/*

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

RUN mkdir -p /run/php \
    && chown -R www-data:www-data /run/php

COPY conf/www.conf /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
COPY conf/php.ini /etc/php/${PHP_VERSION}/fpm/conf.d/99-custom.ini
# The number 99- ensures it loads after the default configs, so it overrides them.

COPY tools/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

WORKDIR /var/www/html

ENTRYPOINT ["/usr/local/bin/setup.sh"]