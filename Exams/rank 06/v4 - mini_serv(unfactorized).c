#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
// ^^^ given
// vvv need to add
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

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

int serverfd = -1, nextid = 0, maxfd = -1;
fd_set  readsockets, writesockets, activesockets;
char    buftowrite[MAX_BUF + 100], buftoread[MAX_BUF];
client_t clients[MAX_CLI];

static void err(char *msg)
{
    if (!msg)
        msg = "Fatal error\n";
    write(2, msg, strlen(msg));
    if (serverfd != -1)
        close(serverfd);
    exit (1);
}

static void sendall(int senderfd)
{
    for (int fd = 0; fd <= maxfd; fd++)
    {
        if (FD_ISSET(fd, &writesockets) && fd != senderfd && fd != serverfd)
            send(fd, buftowrite, strlen(buftowrite), 0);
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;

    if (argc != 2)
        err("Wrong number of arguments\n");

    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd == -1)
        err(NULL);
    bzero(&servaddr, sizeof(servaddr));
    FD_ZERO(&activesockets);
    FD_SET(serverfd, &activesockets);
    maxfd = serverfd;

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
    servaddr.sin_port = htons(atoi(argv[1]));

    if ((bind(serverfd, (const struct sockaddr *) &servaddr, sizeof(servaddr))) != 0)
        err(NULL);
    if (listen(serverfd, 10) != 0)
        err(NULL);
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
            if (fd == serverfd)
            {
                int clientfd = accept(serverfd, NULL, NULL);
                if (clientfd < 0)
                    continue;
                clients[clientfd].id = nextid++;
                if (maxfd < clientfd)
                    maxfd = clientfd;
                FD_SET(clientfd, &activesockets);
                sprintf(buftowrite, "server: client %d just arrived\n", clients[clientfd].id);
                sendall(clientfd);
                break;
            }
            else
            {
                int bytesread = recv(fd, buftoread, 100, 0);
                if (bytesread <= 0)
                {
                    sprintf(buftowrite, "server: client %d just left\n", clients[fd].id);
                    sendall(fd);
                    FD_CLR(fd, &activesockets);
                    close(fd);
                    bzero(clients[fd].msg, sizeof(clients[fd].msg));
                    break;
                }
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
                            bzero(clients[fd].msg, sizeof(clients[fd].msg));
                            j = -1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
