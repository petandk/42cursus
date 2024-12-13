/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/13 20:34:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_comm(char *path, int fdin, t_command *comm, int pipefd[2])
{
	if (fdin == -1)
		return (print_error("no_file"), free(path), 1);
	if (dup2(fdin, STDIN_FILENO) == -1)
		return (print_error("bad_fd"), free(path), 1);
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		return (print_error("bad_fd"), free(path), 1);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, comm->first_argv, NULL) == -1)
		return (print_error("cmd_not_found"), free(path), 1);
	return (free(path), 0);
}

static int	second_comm(char *path, int fdout, t_command *comm, int pipefd[2])
{
	if (fdout == -1)
		return (print_error("perm_denied"), free(path), 1);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (print_error("bad_fd"), free(path), 1);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		return (print_error("bad_fd"), free(path), 1);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, comm->second_argv, NULL) == -1)
		return (print_error("cmd_not_found"), free(path), 1);
	free(path);
	return (0);
}

static void	exec_first(t_command *comm, int pipefd[2])
{
	char	*path;
	int		fdin;

	close(pipefd[0]);
	path = get_path(comm->first_argv[0]);
	if (!path)
	{
		print_error("cmd_not_found");
		free(path);
		exit(1);
	}
	fdin = open(comm->infile, O_RDONLY);
	if (fdin == -1)
	{
		print_error("no_file");
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
	path = get_path(comm->second_argv[0]);
	if (!path)
	{
		print_error("cmd_not_found");
		free(path);
		exit(1);
	}
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
		return (print_error("resource"), 1);
	pid1 = fork();
	if (pid1 == -1)
		return (print_error("no_mem"), close(pipefd[0]), close(pipefd[1]), 1);
	if (pid1 == 0)
		exec_first(comm, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		return (print_error("no_mem"), close(pipefd[0]), close(pipefd[1]), 1);
	if (pid2 == 0)
		exec_second(comm, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (0);
}
