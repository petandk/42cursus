# Apuntes de Estudio: Servidor TCP con `select` (mini_serv)
*<small>&emsp; &emsp; &emsp;El código que aquí se explica pertenece a [v3 - mini_serv(simplified).c](<v3 - mini_serv(simplified).c>)</small>*
## 🧠 Conceptos Core y "Exam Hacks"

Estas son las decisiones de diseño clave para teclear rápido, evitar errores de sintaxis y pasar los tests de rendimiento de la Moulinette:

*   **El truco de `\0` vs `bzero` (Ant-Timeout):** El array `msg` tiene 1.000.000 de posiciones. Si usas `bzero` para limpiarlo en cada mensaje, el tester (que envía miles de mensajes por segundo) te podría suspender por *Timeout* por culpa de la CPU consumida en escribir ceros.
    *   **La solución:** Como las funciones de string (`strlen`, `sprintf`) paran en el primer carácter nulo `\0`, usamos `msg[0] = '\0'`. El resto de la "basura" anterior se queda en memoria, pero el programa se vuelve ciego a ella.
<br>Seguridad mínima, Rendimiento máximo, pero... ¿¿que somos??
*   **`accept` a ciegas:** `accept(serverfd, NULL, NULL)`. No nos importa de qué IP o puerto viene el cliente, solo queremos su *File Descriptor* (fd). Pasar `NULL` nos ahorra declarar un `struct sockaddr_in` extra y su tamaño. Menos variables = menos posibilidades de equivocarse.
*   **`bzero` vs `= {0}` (Supervivencia a `-Werror`):** Para inicializar el struct del servidor (`servaddr`), usamos `bzero(&servaddr, sizeof(servaddr));` en lugar de la abreviatura moderna `= {0}`. 
    *   **El motivo:** Compilamos con `-Wall -Wextra -Werror`. El struct `sockaddr_in` tiene otros structs anidados por dentro. En algunos compiladores estrictos, `= {0}` suelta un warning de *"missing braces around initializer"*. Con `-Werror`, ese warning te suspende el examen sin llegar a probar el código. `bzero` es el método "old-school" 100% seguro a prueba de compiladores estrictos. El tester funciona con uno o con otro... para el examen pongo los dos!
*   **`select` es destructivo:** `select` modifica los `fd_set` que le pasas para dejar "marcados" solo los fds que tienen actividad. Por eso existe `activesockets` (la lista maestra intocable que almacena las conexiones) y `readsockets`/`writesockets` (las copias temporales que le pasamos a `select` para que las destroce y modifique en cada iteración del bucle).

---

## 🔍 Desglose por Funciones

### 1. `main(int argc, char **argv)`
**Objetivo:** Levantar el servidor, configurarlo y mantener el bucle infinito de eventos.
*   **Sockets básicos:** `socket()`, `bind()`, `listen()`. Es la triada obligatoria.
*   **La IP Hardcodeada:** `htonl(0x7F000001)`. Es `127.0.0.1` en hexadecimal. Te salva de tener que memorizar y teclear el número gigante `2130706433`. Fácil de memorizar, 0x7F cinco ceros 1. Aunque el numero gigante te lo dan en el main del examen, almenos para practicar prefiero usar el hexadecimal.
*   **Inicializar la multiplexación:**
    *   `FD_ZERO(&activesockets);` -> Limpia la lista maestra.
    *   `FD_SET(serverfd, &activesockets);` -> Añade el servidor a la lista maestra. Es crucial porque una nueva conexión entrante se detecta como "algo listo para leer" en el fd principal.
    *   `maxfd = serverfd;` -> `select` necesita saber cuál es el fd numéricamente más alto para saber cuántas comprobaciones tiene que hacer internamente.
*   **El Bucle Infinito:**
    *   Restaura las listas: `readsockets = writesockets = activesockets;`.
    *   Llama a `select()`. Se queda bloqueado aquí sin consumir CPU hasta que ocurre algún evento.
    *   Itera desde `fd = 0` hasta `maxfd`.
    *   `if (!FD_ISSET(fd, &readsockets))` -> Si este fd no tiene novedades, `continue`.
    *   Si hay novedad y es el `serverfd` -> Ejecuta `addclient()` (alguien nuevo llama a la puerta).
    *   Si hay novedad y es cualquier otro fd -> Ejecuta `handlemsg()` (un cliente existente nos habla).

### 2. `addclient(void)`
**Objetivo:** Aceptar a un cliente nuevo, asignarle ID, avisar al resto y guardarlo.
*   `clientfd = accept(serverfd, NULL, NULL)` -> Consigue el ticket (fd) para hablar con este cliente.
*   `if (maxfd < clientfd) maxfd = clientfd;` -> Actualiza el límite de `select` si este fd es el más alto hasta ahora.
*   `clients[clientfd].id = nextid++;` -> Asigna el ID usando el propio fd como índice del array (súper eficiente, acceso en O(1)).
*   `FD_SET(clientfd, &activesockets);` -> Mete al cliente en la lista maestra.
*   Genera el mensaje de llegada y llama a `sendall`.

### 3. `handlemsg(int clientfd)`
**Objetivo:** Leer el texto entrante, guardarlo (incluso si llega a trozos) y reenviarlo cuando encuentre un salto de línea.
*   `bytesread = recv(...)`: Lee hasta 100 caracteres.
*   `if (bytesread <= 0)`: Si lee 0 (desconexión controlada) o menor (error), llama a `removeclient()`.
*   **El bucle de ensamblado (La parte más compleja):**
    *   `i` recorre lo que acabamos de leer.
    *   `j = strlen(clients[clientfd].msg)` nos da la longitud actual de lo que el cliente lleva escrito. Así, si el mensaje llega en dos trozos (muy común en TCP), `j` empezará justo donde se quedó el primer trozo, concatenando sin machacar datos.
    *   Copia letra a letra. Si encuentra un `\n`:
        1.  Cambia ese `\n` por `\0` para tener una string válida.
        2.  Construye el texto final en `buftowrite`.
        3.  Envía todo (`sendall`).
        4.  Resetea el buffer del cliente: `clients[clientfd].msg[0] = '\0';`
        5.  `j = -1;` -> Como el bucle `for` va a ejecutar `j++` al terminar el ciclo, ponerlo a `-1` fuerza que en la siguiente vuelta `j` valga `0`, listo para el siguiente mensaje.

### 4. `removeclient(int clientfd)`
**Objetivo:** Limpiar el rastro de un cliente que se va.
*   Genera el mensaje de desconexión y lo envía (`sendall`).
*   `FD_CLR(clientfd, &activesockets);` -> Lo saca de la lista maestra.
*   `close(clientfd);` -> Libera el fd (imprescindible para no tener *fd leaks*).
*   `clients[clientfd].msg[0] = '\0';` -> Limpia su buffer por si el Sistema Operativo recicla ese mismo número de fd para un futuro cliente.

### 5. `sendall(int senderfd)`
**Objetivo:** Mandar el contenido de `buftowrite` a todos los clientes.
*   Itera de `0` a `maxfd`.
*   **Las 3 condiciones del `if`:**
    1.  `FD_ISSET(fd, &writesockets)`: ¿El socket está listo para recibir nuestros datos sin bloquear el programa?
    2.  `fd != senderfd`: No le hagas "eco" al mismo cliente que lo escribió.
    3.  `fd != serverfd`: Al fd del servidor no se le mandan mensajes, solo escucha nuevas conexiones.

### 6. `err(char *msg)`
**Objetivo:** Salida de emergencia.
*   `if (!msg)`: Si le pasamos `NULL`, usa "Fatal error\n" (así ahorramos hacer if/else engorrosos en el main).
*   `write(2, ...)`: Escribe el error en `stderr` (fd 2).
*   Cierra el `serverfd` si ya estaba abierto (previene *leaks* en caso de que falle un `bind` o un `listen`).
