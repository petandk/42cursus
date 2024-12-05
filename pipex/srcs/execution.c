/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/05 16:35:57 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exec_comms(t_command	*comm)
{
	char	*path;
	char	*argv[3];
	int		fdin;
//	int		fdout;

	path = get_path(comm->first_command);
	if (!path)
		return (free(path), 1);
	argv[0] = comm->first_command;
	argv[1] = comm -> first_flags;
	argv[2] = NULL;
	fdin = open(comm->infile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fdin == -1)
	{
		perror("ERROR: cannot open/create file");
		free (path);
		return (1);
	}
	if (dup2(fdin, STDOUT_FILENO) == -1)
	{
		perror("ERROR: cannot redirect to stdout");
		close (fdin);
		free(path);
		return (1);
	}
	close(fdin);
	if (execve(path, argv, NULL) == -1)
	{
		perror("ERROR: execve failed");
		free (path);
		return (1);
	}
	free(path);
	return (0);
}
