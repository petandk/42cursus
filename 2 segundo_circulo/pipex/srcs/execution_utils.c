/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:44:39 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/18 21:36:59 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	first_comm(char *path, int fdin, t_command *comm, int pipefd[2])
{
	if (dup2(fdin, STDIN_FILENO) == -1)
	{
		close(fdin);
		close(pipefd[1]);
		free(path);
		return (print_error("bad_fd", ""), 1);
	}
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
	{
		close(fdin);
		close(pipefd[1]);
		free(path);
		return (print_error("bad_fd", ""), 1);
	}
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, comm->first_argv, NULL) == -1)
	{
		free(path);
		return (print_error("cmd_not_found", comm->first_argv[0]), 1);
	}
	return (free(path), 0);
}

static int	second_comm(char *path, int fdout, t_command *comm, int pipefd[2])
{
	if (fdout == -1)
		return (print_error("perm_denied", ""), free(path), 1);
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		return (print_error("bad_fd", ""), free(path), 1);
	if (dup2(fdout, STDOUT_FILENO) == -1)
		return (print_error("bad_fd", ""), free(path), 1);
	close(pipefd[0]);
	close(pipefd[1]);
	if (execve(path, comm->second_argv, NULL) == -1)
	{
		print_error("cmd_not_found", comm->second_argv[0]);
		return (free(path), 1);
	}
	free(path);
	return (0);
}

static void	exec_first_split(t_command *comm, int fdin, int pipefd, char *path)
{
	if (fdin == -1)
	{
		write(2, "No such file or directory: ", 27);
		write(2, comm->infile, ft_strlen(comm->infile));
		write(2, "\n", 1);
		close(pipefd);
		exit(127);
	}
	if (!path)
	{
		print_error("cmd_not_found", comm->first_argv[0]);
		close(fdin);
		close(pipefd);
		exit(127);
	}
}

void	exec_first(t_command *comm, int pipefd[2])
{
	char	*path;
	int		fdin;

	close(pipefd[0]);
	fdin = open(comm->infile, O_RDONLY);
	path = get_path(comm->first_argv[0]);
	exec_first_split(comm, fdin, pipefd[1], path);
	if (first_comm(path, fdin, comm, pipefd))
	{
		close(fdin);
		close(pipefd[1]);
		exit (127);
	}
	exit(0);
}

void	exec_second(t_command *comm, int pipefd[2])
{
	char	*path;
	int		fdout;

	close(pipefd[1]);
	path = get_path(comm->second_argv[0]);
	if (!path)
	{
		print_error("cmd_not_found", comm->second_argv[0]);
		exit(1);
	}
	fdout = open(comm->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (second_comm(path, fdout, comm, pipefd) != 0)
		close(fdout);
	close(fdout);
	exit(0);
}
