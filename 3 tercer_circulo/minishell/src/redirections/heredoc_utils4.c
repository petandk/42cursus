/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 11:33:53 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/17 19:38:38 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup_here_mem(t_comand_data *cmd)
{
	int	i;

	cmd->heredoc_fd = ft_calloc(cmd->n_heredocs + 1, sizeof(int));
	if (!cmd->heredoc_fd)
		return (-1);
	i = 0;
	while (i < cmd->n_heredocs)
		cmd->heredoc_fd[i++] = -1;
	return (0);
}

static void	clean_open_fds(t_comand_data *cmd, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (cmd->heredoc_fd[i] >= 0)
			close(cmd->heredoc_fd[i]);
		i++;
	}
}

static int	proc_sngl_hd(t_comand_data *cmd, char *file, t_shell **shell, int i)
{
	int	exp;

	if (file[0] == '-')
		exp = 1;
	else
		exp = 0;
	cmd->heredoc_fd[i] = open_hd_pipe(file, shell, exp);
	if (cmd->heredoc_fd[i] == -1)
		return (-1);
	return (0);
}

static int	proc_hd_files(t_comand_data *cmd, t_shell **shell)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cmd->in_count)
	{
		if (cmd->in_file[i][0] == '-' || cmd->in_file[i][0] == '_')
		{
			if (proc_sngl_hd(cmd, cmd->in_file[i], shell, j) == -1)
			{
				clean_open_fds(cmd, j);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	init_all_heredocs(t_comand_data *cmd, int cmd_count, t_shell **shell)
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		cmd[i].n_heredocs = count_heredocs(cmd[i].in_file, cmd[i].in_count);
		if (cmd[i].n_heredocs == 0)
		{
			cmd[i].heredoc_fd = NULL;
			i++;
			continue ;
		}
		if (setup_here_mem(&cmd[i]) == -1)
			return (-1);
		if (proc_hd_files(&cmd[i], shell) == -1)
		{
			cleanup_heredocs(cmd, i);
			return (-1);
		}
		i++;
	}
	return (0);
}
