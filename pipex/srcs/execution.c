/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/10 20:24:11 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_comm(char *path, int fdin, t_command *comm)
{
	char	*argv[3];

	argv[0] = comm->first_command;
	argv[1] = comm -> first_flags;
	argv[2] = NULL;
	if (fdin == -1)
	{
		perror("ERROR: cannot open/create input file");
		free (path);
		return (1);
	}
	if (dup2(fdin, STDOUT_FILENO) == -1)
	{
		perror("ERROR: cannot redirect to stdout");
		free(path);
		return (1);
	}
	if (execve(path, argv, NULL) == -1)
	{
		perror("ERROR: execve failed");
		free (path);
		return (1);
	}
	free(path);
	return (0);
}

static int	second_comm(char *path, int fdin, int fdout, t_command *comm)
{
	char	*argv[3];

	argv[0] = comm->second_command;
	argv[1] = comm-> second_flags;
	argv[2] = NULL;
	if (fdout == -1)
		return (perror("ERROR: cannot open/create output file"), free(path), 1);
	if (dup2(fdin, STDIN_FILENO) == -1)
		return (perror("ERROR: cannot redirect from stdin"), free(path), 1);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		return (perror("ERROR: cannot redirect to stdout"), free(path), 1);
	if (execve(path, argv, NULL) == -1)
		return (perror("ERROR: execve failed"), free(path), 1);
	free(path);
	return (0);
}

static void	exec_first(t_command *comm)
{
	char	*path;
	int		fdin;

	path = get_path(comm->first_command);
	if (!path)
		free(path);
	fdin = open(comm->infile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (first_comm(path, fdin, comm) != 0)
		close(fdin);
	close(fdin);
}

static void	exec_second(t_command *comm)
{
	char	*path;
	int		fdin;
	int		fdout;

	path = get_path(comm->second_command);
	if (!path)
		free(path);
	fdin = open(comm->infile, O_RDONLY);
	fdout = open(comm->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_comm(path, fdin, fdout, comm) != 0)
	{
		close(fdin);
		close(fdout);
	}
	close(fdin);
	close(fdout);
}

int	exec_comms(t_command	*comm)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	pid1 = fork();
	if (pid1 == -1)
		return (perror("Fork failed."), 1);
	if (pid1 == 0)
		exec_first(comm);
	else
	{
		waitpid(pid1, &status, 0);
		pid2 = fork();
		if (pid2 == -1)
			return (perror("Fork failed."), 1);
		if (pid2 == 0)
			exec_second(comm);
		else
		{
			waitpid(pid2, &status, 0);
			unlink(comm->infile);
		}
	}
	return (0);
}
