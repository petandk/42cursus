/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 13:29:36 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/15 16:18:51 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_string_array(char **array, int count)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (i < count && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_command_strings(t_comand_data *cmd)
{
	int	j;

	j = 0;
	while (cmd->comand && cmd->comand[j])
		free(cmd->comand[j++]);
	free(cmd->comand);
	j = 0;
	while (cmd->quote && cmd->quote[j])
		free(cmd->quote[j++]);
	free(cmd->quote);
	if (cmd->quote_count)
		free(cmd->quote_count);
}

static void	free_command_files(t_comand_data *cmd)
{
	int	j;

	free_string_array(cmd->in_file, cmd->in_count);
	free_string_array(cmd->out_file, cmd->out_count);
	if (cmd->heredoc_fd)
	{
		j = 0;
		while (j < cmd->n_heredocs)
		{
			if (cmd->heredoc_fd[j] >= 0)
				close(cmd->heredoc_fd[j]);
			j++;
		}
		free(cmd->heredoc_fd);
	}
}

static void	free_command_quotes(t_comand_data *cmd)
{
	int	j;

	j = 0;
	while (cmd->quote_in && j < cmd->in_count)
	{
		if (cmd->quote_in[j])
			free(cmd->quote_in[j]);
		j++;
	}
	free(cmd->quote_in);
	j = 0;
	while (cmd->quote_out && j < cmd->out_count)
	{
		if (cmd->quote_out[j])
			free(cmd->quote_out[j]);
		j++;
	}
	free(cmd->quote_out);
	if (cmd->quote_in_count)
		free(cmd->quote_in_count);
	if (cmd->quote_out_count)
		free(cmd->quote_out_count);
}

void	free_comand(t_comand_data *comand, int num_comands)
{
	int	i;

	if (!comand)
		return ;
	i = 0;
	while (i < num_comands)
	{
		free_command_strings(&comand[i]);
		free_command_files(&comand[i]);
		free_command_quotes(&comand[i]);
		i++;
	}
	free(comand);
}
