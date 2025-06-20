/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:18:21 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/17 19:07:15 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*child_hd_setup(t_shell **shell, int pipe_fd, int exp, char *deli)
{
	char	*line;
	char	*expanded;

	line = readline("> ");
	if (g_signal == 1)
	{
		if (line)
			free(line);
		close(pipe_fd);
		cleanup_shell(shell);
		exit(130);
	}
	if (!line)
	{
		control_d_error(deli);
		close(pipe_fd);
		cleanup_shell(shell);
		exit(0);
	}
	if (exp && line)
	{
		expanded = heredoc_expansion(line, shell);
		return (free(line), expanded);
	}
	return (line);
}

int	child_heredoc(t_shell *shell, char *delimiter, int pipe_fd, int expand)
{
	char	*line;
	int		result;

	heredoc_child_signals();
	while (1)
	{
		if (g_signal == 1)
		{
			close(pipe_fd);
			cleanup_shell(&shell);
			exit(130);
		}
		line = child_hd_setup(&shell, pipe_fd, expand, delimiter);
		result = process_line(&shell, line, delimiter, pipe_fd);
		if (result == 1)
		{
			close(pipe_fd);
			cleanup_shell(&shell);
			exit(42);
		}
		else if (result == 2)
			break ;
	}
	return (close(pipe_fd), cleanup_shell(&shell), 0);
}

int	process_line(t_shell **shell, char *line, char *delimiter, int pipe_fd)
{
	char	*del_copy;

	(void)shell;
	if (!line)
	{
		del_copy = ft_strdup(delimiter);
		if (del_copy)
			free(del_copy);
		return (1);
	}
	if (ft_strcmp(delimiter, line) == 0)
	{
		free(line);
		return (2);
	}
	ft_putendl_fd(line, pipe_fd);
	free(line);
	return (0);
}
