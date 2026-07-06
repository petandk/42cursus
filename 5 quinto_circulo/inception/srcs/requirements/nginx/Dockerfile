ARG OS_NAME
ARG OS_VERSION

FROM ${OS_NAME}:${OS_VERSION}

# upgrade repos, then install ONLY --no-install-recomends means exactly what is needed to run
RUN apt-get update \
    && apt-get upgrade -y \
    && apt-get install -y --no-install-recommends \
    nginx openssl \
    && rm -rf /var/lib/apt/lists/*


COPY conf/nginx.conf /etc/nginx/nginx.conf

RUN mkdir -p /etc/nginx/ssl

ARG DOMAIN_NAME

RUN openssl req -x509 -nodes -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/server.key \
    -out /etc/nginx/ssl/server.crt \
    -days 365 \
    -subj "/CN=${DOMAIN_NAME}"

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]