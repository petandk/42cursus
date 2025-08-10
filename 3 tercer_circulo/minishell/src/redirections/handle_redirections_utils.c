/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:17:55 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/15 17:50:12 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	out_red(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		if (errno == EACCES)
			printerror("no_perm", file);
		else
			printerror("no_file", file);
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	append(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
	{
		if (errno == EACCES)
			printerror("no_perm", file);
		else
			printerror("no_file", file);
		return (-1);
	}
	dup2(fd, 1);
	close(fd);
	return (0);
}

int	in_red(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		if (errno == EACCES)
			printerror("no_perm", file);
		else
			printerror("no_file", file);
		return (-1);
	}
	dup2(fd, 0);
	close(fd);
	return (0);
}
