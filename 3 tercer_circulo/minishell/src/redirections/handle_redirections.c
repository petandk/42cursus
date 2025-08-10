/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:02:38 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/06 12:23:50 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_files(t_comand_data *cmd)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < cmd->in_count)
	{
		if (cmd->in_file[i][0] == '-' || cmd->in_file[i][0] == '_')
		{
			if (cmd->heredoc_fd && k < cmd->n_heredocs)
			{
				dup2(cmd->heredoc_fd[k], STDIN_FILENO);
				close(cmd->heredoc_fd[k]);
				k++;
			}
		}
		else
		{
			if (in_red(cmd->in_file[i] + 1) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

static int	out_files(char **out_file, int out_count)
{
	int	i;

	i = 0;
	while (i < out_count)
	{
		if (out_file[i][0] == '_')
		{
			if (append(out_file[i] + 1) == -1)
				return (-1);
		}
		else
		{
			if (out_red(out_file[i] + 1) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	handle_redirections(t_comand_data *cmd)
{
	if (cmd->out_file && cmd->out_count)
		if (out_files(cmd->out_file, cmd->out_count) == -1)
			return (-1);
	if (cmd->in_file && cmd->in_count)
		if (in_files(cmd) == -1)
			return (-1);
	return (0);
}
