# Guía Paso a Paso: Reconstrucción del Servidor desde Cero

Esta guía está estructurada en bloques lógicos secuenciales. Pásala a tu programa para machacar la sintaxis, aislar lo que se copia del *given* y consolidar la memoria muscular de cara al examen.
*<small><br><br>&emsp; &emsp; &emsp;El código que aquí se explica pertenece a [v4 - mini_serv(unfactorized).c](<v4 - mini_serv(unfactorized).c>)</small>*

## 1. Cabeceras (Includes)
Empieza por la base del archivo. 
- **Copia del given**: Todas las cabeceras básicas.
- **Añade de memoria**: Las estándar y la necesaria para la multiplexación.

```c
// --- COPIA DEL GIVEN ---
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
// --- AÑADE DE MEMORIA ---
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
```

## 2. Macros, Estructuras y Globales
Todo este bloque va **100% de memoria** antes de ninguna función. Trabajar con globales aquí te salva de lidiar con punteros luego.

```c
// --- ESCRIBE DE MEMORIA ---
enum
{
    MAX_CLI = 2000, 
    MAX_BUF = 1000000
};

typedef struct
{
    int id;
    char msg[MAX_BUF];
}   client_t;

int sockfd = -1, nextid = 0, maxfd = -1;
fd_set  readsockets, writesockets, activesockets;
char    buftowrite[MAX_BUF + 100], buftoread[MAX_BUF];
client_t clients[MAX_CLI];
```

## 3. Funciones de Soporte
Encapsula la lógica repetitiva. Esto también es **100% de memoria**.

```c
// --- ESCRIBE DE MEMORIA ---
static void err(char *msg)
{
    if (!msg)
        msg = "Fatal error\n";
    write(2, msg, strlen(msg));
    if (sockfd != -1)
        close(sockfd);
    exit (1);
}

static void sendall(int senderfd)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, &writesockets) && fd != senderfd && fd != sockfd)
            send(fd, buftowrite, strlen(buftowrite), 0);
    }
}
```

## 4. Setup del `main`
Aquí es donde más reciclas código del *given*, pero hay que adaptarlo. Sigue estos pasos:

1. **Escribe de memoria**: La declaración de `servaddr` y la validación de `argc != 2`.
2. **Copia del given**: Todo el bloque de creación del socket (`socket()`), asignación de IP/Puerto, el `bind()` y el `listen()`.
3. **Cambia esto del given**:
   - Sustituye todos los `printf(...)` y `exit(0)` por `err(NULL)`.
   - Modifica el puerto: cambia `htons(8081)` por `htons(atoi(argv[1]))`.
4. **Añade de memoria**: La inicialización de tus fd_sets y la limpieza del array de clientes.

```c
int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;

    // --- ESCRIBE DE MEMORIA ---
    if (argc != 2)
        err("Wrong number of arguments\n");

    // --- COPIA DEL GIVEN ---
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1)
        err(NULL); // <-- CAMBIA el printf y exit del given por err(NULL)

    // --- AÑADE DE MEMORIA ---
    bzero(&servaddr, sizeof(servaddr));
    FD_ZERO(&activesockets);
    FD_SET(sockfd, &activesockets);
    maxfd = sockfd;

    // --- COPIA DEL GIVEN ---
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(argv[1])); // <-- CAMBIA htons(8081) por htons(atoi(argv[1]))

    if ((bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr))) != 0) 
        err(NULL); // <-- CAMBIA el printf y exit del given por err(NULL)
    
    if (listen(sockfd, 10) != 0) 
        err(NULL); // <-- CAMBIA el printf y exit del given por err(NULL)
    
    // --- AÑADE DE MEMORIA ---
    bzero(&clients, sizeof(clients));
```

## 5. El Bucle Principal y Multiplexación
A partir de aquí es lógica pura **100% de memoria**. Todo el manejo de strings del *given* lo descartas y usas tu propia lógica de volcado carácter a carácter.

```c
// --- ESCRIBE DE MEMORIA ---
    while (1)
    {
        readsockets = writesockets = activesockets;

        if (select(maxfd + 1, &readsockets, &writesockets, 0, 0) <= 0)
            continue;
        for (int fd = 0; fd <= maxfd; fd++)
        {
            if (FD_ISSET(fd, &readsockets) <= 0)
                continue;
```

## 6. Lógica de Conexión: Nuevo Cliente vs Cliente Existente

### A) Es el socket del servidor (`fd == sockfd`) -> Nueva Conexión

```c
// --- ESCRIBE DE MEMORIA ---
            if (fd == sockfd)
            {
                int connfd = accept(sockfd, NULL, NULL);
                if (connfd < 0)
                    continue;
                clients[connfd].id = nextid++;
                if (maxfd < connfd)
                    maxfd = connfd;
                FD_SET(connfd, &activesockets);
                sprintf(buftowrite, "server: client %d just arrived\n", clients[connfd].id);
                sendall(connfd);
                break;
            }
```

### B) Es otro socket -> Recepción de Datos

```c
// --- ESCRIBE DE MEMORIA ---
            else
            {
                int bytesread = recv(fd, buftoread, 100, 0);
                
                // Caso desconexión
                if (bytesread <= 0)
                {
                    sprintf(buftowrite, "server: client %d just left\n", clients[fd].id);
                    sendall(fd);
                    FD_CLR(fd, &activesockets);
                    close(fd);
                    clients[fd].msg[0] = '\0';
                    break;
                }
                // Caso lectura normal
                else
                {
                    buftoread[bytesread] = '\0';
                    for (int i = 0, j = strlen(clients[fd].msg); i < bytesread; i++, j++)
                    {
                        clients[fd].msg[j] = buftoread[i];
                        if (clients[fd].msg[j] == '\n')
                        {
                            clients[fd].msg[j] = '\0';
                            sprintf(buftowrite, "client %d: %s\n", clients[fd].id, clients[fd].msg);
                            sendall(fd);
                            clients[fd].msg[0] = '\0';
                            j = -1;
                        }
                    }
                }
            }
        }
    }
}
```