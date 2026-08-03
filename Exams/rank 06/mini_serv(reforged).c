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
}	client_t;

int sockfd = -1, gid = 0, maxfd = -1;
fd_set rd, wr, cur;
char str[MAX_BUF + 100], rec[MAX_BUF];
client_t client[MAX_CLI];

static void err(char *msg)
{
	if (!msg)
		msg = "Fatal error\n";
	write(2, msg, strlen(msg));
	if (sockfd != -1)
		close(sockfd);
	exit (1);
}

static void send_all(int except)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &wr) && fd != except && fd != sockfd)
			send(fd, str, strlen(str), 0);
	}
}

static void add_client(void)
{
	struct sockaddr cli;
	socklen_t len = sizeof(cli);
	int connfd = accept(sockfd, &cli, &len);
	if (connfd < 0)
		return;
	if (maxfd < connfd)
		maxfd = connfd;
	client[connfd].id = gid++;
	FD_SET(connfd, &cur);
	sprintf(str, "server: client %d just arrived\n", client[connfd].id);
	send_all(connfd);
}

static void remove_client(int fd)
{
	sprintf(str, "server: client %d just left\n", client[fd].id);
	send_all(fd);
	FD_CLR(fd, &cur);
	close(fd);
	bzero(client[fd].msg, sizeof(client[fd].msg));
}

static void handle_msg(int fd)
{
	int ret = recv(fd, rec, 100, 0);
	if (ret <= 0)
	{
		remove_client(fd);
		return;
	}
	rec[ret] = '\0';
	for (int i = 0, j = strlen(client[fd].msg); i < ret; i++, j++)
	{
		client[fd].msg[j] = rec[i];
		if (client[fd].msg[j] == '\n')
		{
			client[fd].msg[j] = '\0';
			sprintf(str, "client %d: %s\n", client[fd].id, client[fd].msg);
			send_all(fd);
			bzero(client[fd].msg, sizeof(client[fd].msg));
			j = -1;
		}
	}
}

int main(int argc, char **argv)
{
	struct sockaddr_in servaddr;

	if (argc != 2)
		err("Wrong number of arguments\n");

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		err(NULL);

	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 => num is given but can use 0x7F000001 instead
	servaddr.sin_port = htons(atoi(argv[1]));
  
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0)
		err(NULL);
	if (listen(sockfd, 10) != 0)
		err(NULL);

	bzero(&client, sizeof(client));
	FD_ZERO(&cur);
	FD_SET(sockfd, &cur);
	maxfd = sockfd;

	while(1)
	{
		rd = wr = cur;
		if (select (maxfd + 1, &rd, &wr, 0, 0) <= 0)
			continue;

		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (!FD_ISSET(fd, &rd))
				continue;
			if (fd == sockfd)
				add_client();
			else
				handle_msg(fd);
		}
	}
	return 0;
}