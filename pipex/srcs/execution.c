/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/08 01:41:51 by rmanzana         ###   ########.fr       */
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
	ft_printf("second comm");
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

int	exec_comms(t_command	*comm)
{
	char	*path;
	int		fdin;
	int		fdout;

	path = get_path(comm->first_command);
	if (!path)
		return (free(path), 1);
	fdin = open(comm->infile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (first_comm(path, fdin, comm) != 0)
		return (close(fdin), 1);
	free(path);
	path = get_path(comm->second_command);
	if (!path)
		return (close(fdin), free(path), 1);
	fdout = open(comm->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (second_comm(path, fdin, fdout, comm) != 0)
		return (close(fdin), close(fdout), 1);
	close(fdin);
	close(fdout);
	unlink(comm->infile);
	return (0);
}
