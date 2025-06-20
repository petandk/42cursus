/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils4helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:16:33 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/17 19:46:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_hd_pipe(char *delimiter, t_shell **shell, int expand)
{
	t_list	*lines;
	t_list	*tmp;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (ft_putendl_fd("pipe", 2), -1);
	lines = ft_heredoc(&delimiter, 1, shell, expand);
	if (!lines && errno == EINTR)
		return (close(pipefd[0]), close(pipefd[1]), -1);
	if (!lines)
	{
		close(pipefd[1]);
		return (pipefd[0]);
	}
	tmp = lines;
	while (tmp)
	{
		ft_putendl_fd(tmp->content, pipefd[1]);
		tmp = tmp->next;
	}
	ft_lstclear(&lines, free);
	close(pipefd[1]);
	return (pipefd[0]);
}

int	count_heredocs(char **in_file, int in_count)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < in_count)
	{
		if (in_file[i][0] == '-' || in_file[i][0] == '_')
			count++;
		i++;
	}
	return (count);
}

void	cleanup_heredocs(t_comand_data *cmd, int cmd_count)
{
	int	i;
	int	j;

	i = 0;
	while (i < cmd_count)
	{
		if (cmd[i].heredoc_fd)
		{
			j = 0;
			while (j < cmd[i].n_heredocs)
			{
				if (cmd[i].heredoc_fd[j] != -1)
					close(cmd[i].heredoc_fd[j]);
				j++;
			}
			free(cmd[i].heredoc_fd);
			cmd[i].heredoc_fd = NULL;
		}
		i++;
	}
}
