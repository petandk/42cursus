#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
//^^^ given
//vvv eed to add
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>

enum
{
	MAXCLI = 2000,
	MAXBUF = 1000000
};

typedef struct
{
	int id;
	char msg[MAXBUF];
}	client_t;

int serverfd = -1, nextid = 0, maxfd = -1;
fd_set activesockets, readsockets, writesockets;
char buftowrite[MAXBUF + 100], buftoread[MAXBUF];
client_t clients[MAXCLI];

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

static void addclient(void)
{
	struct sockaddr cli;
	socklen_t len = sizeof(cli);

	int clientfd = accept(serverfd, &cli, &len);
	if (clientfd < 0)
		return;

	if (maxfd < clientfd)
		maxfd = clientfd;

	clients[clientfd].id = nextid++;
	FD_SET(clientfd, &activesockets);

	sprintf(buftowrite, "server: client %d just arrived\n", clients[clientfd].id);
	sendall(clientfd);
}

static void removeclient(int clientfd)
{
	sprintf(buftowrite, "server: client %d just left\n", clients[clientfd].id);
	sendall(clientfd);

	FD_CLR(clientfd, &activesockets);
	close(clientfd);
	bzero(clients[clientfd].msg, sizeof(clients[clientfd].msg));
}

static void handlemsg(int clientfd)
{
	int bytesread = recv(clientfd, buftoread, 100, 0);
	if (bytesread <= 0)
	{
		removeclient(clientfd);
		return;
	}

	buftoread[bytesread] = '\0';
	for (int i = 0, j = strlen(clients[clientfd].msg); i < bytesread; i++, j++)
	{
		clients[clientfd].msg[j] = buftoread[i];
		if (clients[clientfd].msg[j] == '\n')
		{
			clients[clientfd].msg[j] = '\0';
			sprintf(buftowrite, "client %d: %s\n", clients[clientfd].id, clients[clientfd].msg);
			sendall(clientfd);
			bzero(clients[clientfd].msg, sizeof(clients[clientfd].msg));
			j = -1;
		}
	}
}

int main(int argc, char **argv)
{
	struct sockaddr_in servaddr;

	if (argc != 2)
		err("Wrong number of arguments\n");

	serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if (serverfd == -1)
		err(NULL);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(argv[1]));

	if ((bind(serverfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(NULL);
	if (listen(serverfd, 10) != 0)
		err(NULL);

	bzero(&clients, sizeof(clients));
	FD_ZERO(&activesockets);
	FD_SET(serverfd, &activesockets);
	maxfd = serverfd;

	while (1)
	{
		readsockets = writesockets = activesockets;

		if (select(maxfd + 1, &readsockets, &writesockets, 0, 0) <= 0)
			continue;

		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (!FD_ISSET(fd, &readsockets))
				continue;

			if (fd == serverfd)
				addclient();
			else
				handlemsg(fd);
		}
	}
	return 0;
}