/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_files_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 08:57:16 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/12 09:09:53 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_quotes	*init_empty_quotes(void)
{
	t_quotes	*quotes;

	quotes = ft_calloc(2, sizeof(t_quotes));
	if (!quotes)
		return (NULL);
	quotes[0].quote = 0;
	quotes[0].quote_start = -1;
	quotes[0].quote_end = -1;
	quotes[1].quote = 0;
	quotes[1].quote_start = -1;
	quotes[1].quote_end = -1;
	return (quotes);
}

static t_quotes	*init_quotes_array(t_token *tk, int index, int *count)
{
	t_quotes		*quotes;
	int				qcount;

	qcount = tk[index].quote_count;
	if (qcount > 0 && tk[index].quotes)
	{
		quotes = ft_calloc(qcount + 1, sizeof(t_quotes));
		if (!quotes)
			return (NULL);
		copy_quotes(quotes, tk[index].quotes, qcount);
	}
	else
	{
		quotes = init_empty_quotes();
		if (!quotes)
			return (NULL);
		qcount = 0;
	}
	*count = qcount;
	return (quotes);
}

void	process_output_redirection(t_comand_data *cmd
		, t_token *tk, int *idx, char *str)
{
	int	count;

	cmd->quote_out[idx[0]] = init_quotes_array(tk, idx[2] + 1, &count);
	if (!cmd->quote_out[idx[0]])
		return ;
	cmd->quote_out_count[idx[0]] = count;
	in_out_file(&cmd->out_file[idx[0]++], str);
}

void	process_input_redirection(t_comand_data *cmd
		, t_token *tk, int *idx, char *str)
{
	int	count;

	cmd->quote_in[idx[1]] = init_quotes_array(tk, idx[2] + 1, &count);
	if (!cmd->quote_in[idx[1]])
		return ;
	cmd->quote_in_count[idx[1]] = count;
	in_out_file(&cmd->in_file[idx[1]++], str);
}
