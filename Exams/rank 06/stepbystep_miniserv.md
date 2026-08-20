# Mini_serv - Step by Step Guide

Esta guía detalla paso a paso cómo estructurar el ejercicio `mini_serv`. El formato diferencia visualmente las partes que debes copiar y las partes que debes escribir o modificar.
*<small><br><br>&emsp; &emsp; &emsp;El código que aquí se explica pertenece a [v5 - mini_serv(final-aproved).c](<v5 - mini_serv(final-aproved).c>)</small>*

### <span style="color:blue">Leyenda</span>
* 📋 **<span style="color:green">Copiar / Modificar:</span>** Código que debes extraer del  [archivo que te dan](<given_main.c>) y adaptar.
* ✍️ **<span style="color:orange">Escribir:</span>** Código que debes memorizar o deducir e implementar tú mismo.

---

## 1. Cabeceras y Estructuras Globales

📋 **<span style="color:green">Copiar:</span>** Las cabeceras que te proporcionan en el main de prueba.

✍️ **<span style="color:orange">Escribir:</span>** Las estructuras, variables globales y las funciones de utilidad (`err` y `sendall`).

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

#define MAXCLI 2000
#define MAXBUF 10000000 // -- Al ver las traces he visto que tenia un problema de buffer, así que he añadido un 0 aquí (ahora son 7 '0s')

typedef struct
{
    int id;
    char msg[MAXBUF];
}   client_t;

int sockfd = -1, maxfd = -1, nextid = 0;
char buftowrite[MAXBUF + 100], buftoread[MAXBUF];
fd_set writesockets, readsockets, activesockets;
client_t clients[MAXCLI];

static void err(char *msg)
{
    if (!msg)
        msg = "Fatal Error\n";
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

## 2. Main y Configuración de Sockets

Empieza el main validando los argumentos.

```c
int main(int argc, char *argv[])
{
    if (argc != 2)
        err("Wrong number of arguments\n");
```

📋 **<span style="color:green">Copiar y Modificar:</span>** La estructura `sockaddr_in`. Quita la variable `cli` que suele venir por defecto.
```c
    struct sockaddr_in servaddr;
```

📋 **<span style="color:green">Copiar y Modificar:</span>** Las líneas de creación del socket (`sockfd = socket(...)`). Cambia lo que haya dentro de los corchetes del chequeo de error por una llamada a tu función: `err(NULL);`.

✍️ **<span style="color:orange">Escribir:</span>** La inicialización de la estructura de red y los file descriptors.
```c
    bzero(&servaddr, sizeof(servaddr));
    FD_ZERO(&activesockets);
    FD_SET(sockfd, &activesockets);
    maxfd = sockfd;
```

📋 **<span style="color:green">Copiar y Modificar:</span>**
1. Las 3 líneas de configuración de `servaddr`. Cambia el puerto estático (`htons(8081)`) por el argumento del programa: `htons(atoi(argv[1]));`.
2. Las líneas de `bind` y `listen`. Al igual que antes, cambia los bloques de error por `err(NULL);`.

---

## 3. Bucle Principal y Select

✍️ **<span style="color:orange">Escribir:</span>** Limpia el array de clientes y abre el bucle infinito para el `select`.

```c
    bzero(&clients, sizeof(clients));

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

---

## 4. Gestión de Nuevas Conexiones

Si el fd activo es el `sockfd`, significa que un cliente nuevo se quiere conectar.

```c
            if (fd == sockfd)
            {
```

📋 **<span style="color:green">Copiar y Modificar:</span>** La línea de la función `accept`. Cambia los dos últimos valores por `NULL` y acuerdate de poner int al principio ya que en esta solución aún no la hemos creado.
> 💡 *Tip: Es bueno saber que sus tipos originales son `(struct sockaddr *)&cli` y `(socklen_t *)&len` (con `int len = sizeof(cli);`) por si acaso da fallo de segmentación usar NULL en el sistema del examen. De todas formas, la otra version esta en el archivo que te dan, solo lo he simplificado a NULL por capricho.*

📋 **<span style="color:green">Copiar y Modificar:</span>** El `if` de comprobación de error del `accept`. Cambia su interior por un simple `continue;`.

✍️ **<span style="color:orange">Escribir:</span>** Registra al cliente, añádelo al set y manda el mensaje de llegada.

```c
                clients[connfd].id = nextid++;
                FD_SET(connfd, &activesockets);
                if (maxfd < connfd)
                    maxfd = connfd;
                sprintf(buftowrite, "server: client %d just arrived\n", clients[connfd].id);
                sendall(connfd);
                break;
            }
```

---

## 5. Lectura y Desconexión

Si el fd activo es distinto a `sockfd`, se trata de un cliente existente enviando datos o marchándose.

✍️ **<span style="color:orange">Escribir:</span>** Bloque `else` con el `recv` y la lógica de parseo de mensajes.

```c
            else
            {
                /*
                    He hecho diferentes pruebas durante el examen y pegando el subject entero, pasa sin problemas, pero las traces
                    decían que no, no se si el server añade delay o que, pero se comía trozos... solución? buffer mas grande!
                */
                int bytesread = recv(fd, buftoread, 1000, 0); 
                
                // caso desconexion
                if (bytesread <= 0)
                {
                    sprintf(buftowrite, "server: client %d just left\n", clients[fd].id);
                    sendall(fd);
                    FD_CLR(fd, &activesockets);
                    close(fd);
                    clients[fd].msg[0] = '\0';
                    break;
                }
                else // caso lectura normal
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
