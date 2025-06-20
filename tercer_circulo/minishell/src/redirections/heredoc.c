/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:19:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/17 19:02:19 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	heredoc_fork(int pipe_fd[2], t_shell *shell, char *deli, int exp)
{
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		return (-1);
	pid = fork();
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		return (-1);
	}
	if (pid == 0)
	{
		g_signal = 0;
		close(pipe_fd[0]);
		child_heredoc(shell, deli, pipe_fd[1], exp);
		exit(0);
	}
	return (pid);
}

t_list	*handle_heredoc(char *delimiter, t_shell **shell, int expand)
{
	int		pipe_fd[2];
	pid_t	pid;
	t_list	*result;

	heredoc_parent_signals();
	pid = heredoc_fork(pipe_fd, *shell, delimiter, expand);
	if (pid == -1)
	{
		shell_signals();
		return (NULL);
	}
	result = parent_process_heredoc(pipe_fd, pid, shell);
	return (result);
}

t_list	*ft_heredoc(char **input, int num_brackets, t_shell **shell, int expand)
{
	t_list		*lines;
	int			old_errno;

	lines = NULL;
	heredoc_parent_signals();
	old_errno = errno;
	lines = ft_hdc_helper(input, num_brackets, shell, expand);
	if (!lines && errno == EINTR)
		(*shell)->exit_status = 130;
	else
		errno = old_errno;
	shell_signals();
	return (lines);
}
