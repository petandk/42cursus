# Apuntes de Estudio: Servidor TCP con select (mini_serv)
*<small>&emsp; &emsp; &emsp;El código que aquí se explica pertenece a [v4 - mini_serv(unfactorized).c](<v4 - mini_serv(unfactorized).c>)</small>*

## 🧠 Trucos y cositas que te salvan el examen
Aquí van las decisiones clave para ir rápido, no liarla con la sintaxis, y que la Moulinette no te trolee con un timeout:

*   **`\0` en vez de bzero (el anti-timeout):** El `msg` tiene 1.000.000 de huecos. Si le metes bzero cada vez que llega un mensaje, y el tester te está bombardeando con miles de mensajes por segundo, la CPU se come tanto tiempo poniendo ceros que te puede saltar un Timeout. Feo.<br>La chapuza que funciona: las funciones de string (`strlen`, `sprintf`...) se paran en el primer `\0` que pillan. Así que basta con `msg[0] = '\0'`. La basura de antes se queda ahí tirada en memoria, pero el programa ya ni la mira.
    <br>Seguridad mínima, rendimiento máximo, pero bueno... ¿¿qué somos?? 🦁🦁🦁🦁🦁🦁🦁🦁🦁🦁
*   **La IP que da el enunciado:** te dan `htonl(2130706433)`, o sea 127.0.0.1. Ese número es una pesadilla para memorizar o teclear sin cagarla con los nervios del examen.<br>El truco de coleguilla es pensarlo en hexadecimal: `htonl(0x7F000001)` — literalmente `0x7F`, cinco ceros y un `1`. Mismo valor, pero mil veces más fácil de recordar y de comprobar de un vistazo. En el `.c` final dejamos el decimal porque es lo que viene en el enunciado, pero si quieres practicar tecleándolo de memoria, tira del hex.
*   **accept sin mirar quién llama:** `accept(sockfd, NULL, NULL)`. Nos la suda de qué IP o puerto viene el cliente, solo queremos su fd. Pasando `NULL` te ahorras declarar un `sockaddr_in` extra y su tamaño. Menos variables, menos líos.
*   **bzero en vez de = {0} (para que -Werror no te arruine el día):** Para vaciar el `servaddr` usamos `bzero(&servaddr, sizeof(servaddr));` en vez del `= {0}` moderno. Por qué: compilamos con `-Wall -Wextra -Werror`, y `sockaddr_in` tiene structs anidados por dentro. En algunos compiladores estrictos, `= {0}` te suelta un warning de "missing braces around initializer" — y con `-Werror` eso te frena en seco antes de que nadie pruebe tu código. `bzero` es el método viejuno pero indestructible. El tester traga los dos, pero para el examen yo pongo `bzero` siempre, por si las moscas.

### ⚠️ El truco de las listas: Por qué `select` te destroza los `fd_set`
Para entenderlo, tienes que pensar en qué es realmente un `fd_set` en C. No es un vector ni un array normal, es **un bitmask** (una tira larguísima de ceros y unos). Cada posición representa un File Descriptor (el bit 3 es el fd 3, el bit 4 es el fd 4, etc.). Si el bit está a `1`, significa *"estoy vigilando este fd"*.

El problema es que la función `select()` es **destructiva**. Trabaja así:
1. **La petición (Lo que le pasas):** Tú le entregas `readsockets` y `writesockets` diciéndole: *"Oye `select`, pausa el programa y avísame en cuanto pase algo en los fds que tienen un `1`"*.
2. **La masacre (Lo que te devuelve):** Cuando por fin pasa algo (un cliente envía un mensaje o el server recibe una conexión nueva), `select` despierta y **modifica esas mismas variables** que le pasaste. Pone a `0` todos los fds que estaban callados, y deja a `1` **SOLO** los fds donde ha habido movimiento.

**¿Por qué necesitamos `activesockets`?**
Como `select` te acaba de borrar todos los `1` de los clientes inactivos, si le hubieras pasado tu lista original, **¡acabarías de perder el rastro de todos los clientes que no hablaron en ese microsegundo!** En la siguiente vuelta, tu servidor habría olvidado que existen y jamás volvería a leerlos.

Por eso usamos la **estrategia de la Copia Maestra**:
*   🛡️ **`activesockets` (La lista maestra, intocable):** Es el registro real. Aquí solo metemos mano con `FD_SET` cuando alguien entra (`accept()`) y con `FD_CLR` cuando alguien se pira (`close()`). **A `select` jamás se le pasa esta variable.**
*   💥 **`readsockets` y `writesockets` (La carne de cañón):** Son variables temporales. En cada vuelta del bucle infinito, las restauramos copiando la lista maestra de golpe (`readsockets = writesockets = activesockets`). Así, le entregamos copias frescas a `select` para que las machaque a gusto y nos chive exactamente qué fds tienen datos nuevos para leer o escribir, sin perder nuestro registro original.

*   **Todo metido en main (la versión "unfactorized"):** a diferencia de la v3, aquí no hay addclient/handlemsg/removeclient como funciones aparte. Todo el rollo de gestionar un fd con actividad (cliente nuevo, mensaje, desconexión) va directo dentro del mismo for de main(). Se teclea más rápido bajo presión, pero cuesta más de leer. `sendall` y `err` sí siguen siendo funciones propias porque se llaman desde varios sitios.

---

## 🔍 Qué hace cada trozo

### 1. `main(int argc, char **argv)`
La idea: levantar el server, dejarlo configurado, y quedarse en bucle infinito atendiendo lo que va pasando.

*   **Lo básico de sockets:** `socket()`, `bind()`, `listen()`. El trío de siempre, sin sorpresas.
*   **Preparando el multiplexado:**
    *   `FD_ZERO(&activesockets);` -> limpia la lista maestra.
    *   `FD_SET(sockfd, &activesockets);` -> mete al server ahí dentro. Importante, porque una conexión nueva se detecta como "hay algo para leer" en ese fd.
    *   `maxfd = sockfd;` -> select necesita saber cuál es el fd más alto para no tener que rebuscar de más.
*   **El bucle que no acaba nunca:**
    *   **Refresca las listas:** `readsockets = writesockets = activesockets;` *(Activesockets no se toca, mantiene la lista intocable de sockets, y readsockets/writesockets se modifican y machacan al pasárselas a select, tal y como se explica arriba).*
    *   Llama a `select()`, que se queda ahí parado sin gastar CPU hasta que pasa algo.
    *   Recorre desde `fd = 0` hasta `maxfd`.
    *   `if (FD_ISSET(fd, &readsockets) <= 0) continue;` -> si este fd no tiene nada nuevo, al siguiente.
    *   Si hay novedad y `fd == sockfd` -> tira para el bloque de cliente nuevo (punto 2).
    *   Si hay novedad en cualquier otro fd -> tira para el bloque de mensaje entrante (punto 3).

### 2. Bloque de cliente nuevo (`fd == sockfd`)
La idea: aceptar al que llama, darle un ID, avisar a los demás y guardarlo.

*   `connfd = accept(sockfd, NULL, NULL)` -> te da el fd para hablar con este cliente.
*   `if (maxfd < connfd) maxfd = connfd;` -> si este fd es el más alto hasta ahora, actualiza el tope.
*   `clients[connfd].id = nextid++;` -> Aquí hacemos dos cosas clave:
    1. Usamos el propio `connfd` como índice del array (`clients[connfd]`). Así el acceso a los datos de ese cliente es O(1): si el fd es 7, vamos directo a la posición 7 sin hacer bucles para buscarlo.
    2. Le asignamos un `id` secuencial (`nextid++`) porque el enunciado exige numerar a los clientes en orden de llegada (0, 1, 2...), sin importar qué número de fd aleatorio les haya dado el sistema.
*   `FD_SET(connfd, &activesockets);` -> lo mete en la lista maestra.
*   Prepara el mensaje de "acabo de llegar" y lo manda con `sendall(connfd)`.
*   `break;` -> corta el for en esta vuelta, porque `maxfd` puede haber cambiado y ya no te puedes fiar de las listas hasta que `select` vuelva a correr.

### 3. Bloque de mensaje entrante (`fd != sockfd`)
La idea: leer lo que llega, ir guardándolo aunque venga en trozos, y mandarlo en cuanto aparezca un salto de línea.

*   `bytesread = recv(fd, buftoread, 100, 0)`: lee hasta 100 caracteres.
*   Si `bytesread <= 0` (se desconectó o hubo error) -> tira para el bloque de desconexión (punto 4).
*   Si hay datos, el bucle chungo de montar el mensaje:
    *   `i` recorre lo que se acaba de leer.
    *   `j = strlen(clients[fd].msg)` te dice cuánto llevaba ya escrito el cliente. Así, si el mensaje llega partido en dos paquetes TCP (que pasa mucho), `j` arranca justo donde se quedó el trozo anterior, sin pisar nada.
    *   Va copiando letra a letra. Si pilla un `\n`:
        *   Lo cambia por `\0` para tener un string decente.
        *   Monta el texto final en `buftowrite`.
        *   Lo manda con `sendall(fd)`.
        *   Vacía el buffer del cliente: `clients[fd].msg[0] = '\0';`
        *   `j = -1;` -> como el for hace `j++` al final del ciclo, poniéndolo a -1 consigue que la próxima vuelta `j` empiece en 0, listo para el siguiente mensaje.

### 4. Bloque de desconexión (`bytesread <= 0`)
La idea: limpiar todo rastro de un cliente que se va.

*   Prepara el mensaje de "me piro" y lo manda (`sendall(fd)`).
*   `FD_CLR(fd, &activesockets);` -> lo saca de la lista maestra.
*   `close(fd);` -> libera el fd, que si no vas dejando fugas por ahí.
*   `clients[fd].msg[0] = '\0';` -> limpia su buffer, por si el sistema operativo recicla ese mismo número de fd para otro cliente más adelante.
*   `break;` -> igual que antes, cortamos el for porque tras el `FD_CLR` las listas ya no cuadran con la realidad.

### 5. `sendall(int senderfd)`
La idea: mandar lo que hay en `buftowrite` a todo el mundo.

*   Recorre de 0 a `maxfd`.
*   Las 3 condiciones para mandar algo:
    *   `FD_ISSET(fd, &writesockets)`: ¿este socket puede recibir datos ahora mismo sin bloquear?
    *   `fd != senderfd`: no le hagas eco al mismo que lo escribió.
    *   `fd != sockfd`: al fd del server no le mandes nada, ese solo escucha conexiones nuevas.

### 6. `err(char *msg)`
La idea: la salida de emergencia cuando algo revienta.

*   `if (!msg)`: si le pasas NULL, tira de "Fatal error\n" por defecto, así te ahorras ifs raros en el main.
*   `write(2, ...)`: escribe el error en stderr (fd 2).
*   Cierra `sockfd` si ya estaba abierto, para no dejar fugas si petan bind o listen.