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

#define MAXCLI 2000
#define MAXBUF 1000000

typedef struct
{
    int id;
    char msg[MAXBUF];
}   client_t;

int sockfd = -1, nextid = 0, maxfd = -1;
fd_set  readsockets, writesockets, activesockets;
char    buftowrite[MAXBUF + 100], buftoread[MAXBUF];
client_t clients[MAXCLI];

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

int main(int argc, char *argv[])
{
    struct sockaddr_in servaddr;

    if (argc != 2)
        err("Wrong number of arguments\n");

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
        err(NULL);
    bzero(&servaddr, sizeof(servaddr));
    FD_ZERO(&activesockets);
    FD_SET(sockfd, &activesockets);
    maxfd = sockfd;

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1 but memorize 0x7f000001 just in case
    servaddr.sin_port = htons(atoi(argv[1]));

    if ((bind(sockfd, (const struct sockaddr *) &servaddr, sizeof(servaddr))) != 0)
        err(NULL);
    if (listen(sockfd, 10) != 0)
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
            else
            {
                int bytesread = recv(fd, buftoread, 1000, 0);
                if (bytesread <= 0)
                {
                    sprintf(buftowrite, "server: client %d just left\n", clients[fd].id);
                    sendall(fd);
                    FD_CLR(fd, &activesockets);
                    close(fd);
                    clients[fd].msg[0] = '\0';
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
                            clients[fd].msg[0] = '\0';
                            j = -1;
                        }
                    }
                }
            }
        }
    }
}
