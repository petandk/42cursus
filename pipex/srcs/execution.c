/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/11 18:49:51 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_comm(char *path, int fdin, t_command *comm, int pipefd[2])
{
	char	*argv[3];

	argv[0] = comm->first_command;
	argv[1] = comm -> first_flags;
	argv[2] = NULL;
	if (fdin == -1)
	{
		perror("ERROR: cannot open/create input file");
		return (free(path), 1);
	}
	if (dup2(fdin, STDIN_FILENO) == -1)
	{
		perror("ERROR: cannot redirect to stdin");
		return (free(path), 1);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("ERROR: cannot redirect to stdout");
		return (free(path), 1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, argv, NULL) == -1)
		return (perror("ERROR: execve failed"), free(path), 1);
	return (free(path), 0);
}

static int	second_comm(char *path, int fdout, t_command *comm, int pipefd[2])
{
	char	*argv[3];

	argv[0] = comm->second_command;
	argv[1] = comm-> second_flags;
	argv[2] = NULL;
	if (fdout == -1)
		return (perror("ERROR: cannot open/create output file"), free(path), 1);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (perror("ERROR: cannot redirect from stdin"), free(path), 1);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		return (perror("ERROR: cannot redirect to stdout"), free(path), 1);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, argv, NULL) == -1)
		return (perror("ERROR: execve failed"), free(path), 1);
	free(path);
	return (0);
}

static void	exec_first(t_command *comm, int pipefd[2])
{
	char	*path;
	int		fdin;

	close(pipefd[0]);
	path = get_path(comm->first_command);
	if (!path)
		free(path);
	fdin = open(comm->infile, O_RDONLY);
	if (fdin == -1)
	{
		perror("ERROR: Input file doesn't exist or cannot be opened.");
		free(path);
		exit(1);
	}
	if (first_comm(path, fdin, comm, pipefd) != 0)
		close(fdin);
	close(fdin);
	exit(1);
}

static void	exec_second(t_command *comm, int pipefd[2])
{
	char	*path;
	int		fdout;

	close(pipefd[1]);
	path = get_path(comm->second_command);
	if (!path)
		free(path);
	fdout = open(comm->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_comm(path, fdout, comm, pipefd) != 0)
		close(fdout);
	close(fdout);
	exit(1);
}

int	exec_comms(t_command	*comm)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
		return (perror("Pipe failed"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (perror("Fork failed."), close(pipefd[0]), close(pipefd[1]), 1);
	if (pid1 == 0)
		exec_first(comm, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Fork failed."), close(pipefd[0]), close(pipefd[1]), 1);
	if (pid2 == 0)
		exec_second(comm, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}
