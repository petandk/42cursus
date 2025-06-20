/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:01:55 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/16 14:33:16 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_quotes(char *str, int i, int q, int in_quote)
{
	while (str[i])
	{
		if ((str[i] == '\'') || (str[i] == '"'))
		{
			if (!in_quote)
			{
				in_quote = str[i];
				q++;
			}
			else if (in_quote == str[i])
			{
				in_quote = 0;
				q++;
			}
		}
		i++;
	}
	if ((q % 2) > 0)
		return (q / 2 + 1);
	return (q / 2);
}

void	copy_quotes(t_quotes *dst, t_quotes *src, int count)
{
	int	q;

	q = 0;
	while (q < count)
	{
		dst[q].quote = src[q].quote;
		dst[q].quote_start = src[q].quote_start;
		dst[q].quote_end = src[q].quote_end;
		q++;
	}
	dst[q].quote = 0;
	dst[q].quote_start = -1;
	dst[q].quote_end = -1;
}

void	alloc_and_copy1(t_comand_data *cmd, t_token *token, t_ind *ind, int k)
{
	int	count;

	count = token[ind->i].quote_count;
	cmd->quote[k] = ft_calloc(count + 1, sizeof(t_quotes));
	if (!malloc_test(cmd->quote[k]))
		exit(1);
	cmd->comand[k] = ft_strdup(token[ind->i].str);
	cmd->quote_count[k] = count;
	copy_quotes(cmd->quote[k], token[ind->i].quotes, count);
}

int	chek_double(char a, char b, int *i)
{
	if (a == b)
	{
		*i += 2;
		return (1);
	}
	return (0);
}

void	register_unclosed_quote(t_token_data *data, t_quote_tracker *qt)
{
	if (data->j == 0)
		data->token[data->j].str = NULL;
	if (data->token[data->j].quotes)
	{
		free(data->token[data->j].quotes);
		data->token[data->j].quotes = NULL;
	}
	if (!data->token[data->j].quotes)
		data->token[data->j].quotes = malloc(sizeof(t_quotes));
	if (data->token[data->j].quotes)
	{
		if (qt->active == 1)
			data->token[data->j].quotes[0].quote = 1;
		else
			data->token[data->j].quotes[0].quote = 2;
		data->token[data->j].quotes[0].quote_start = 0;
		data->token[data->j].quotes[0].quote_end = -1;
		data->token[data->j].quotes[0].closed = 0;
	}
	data->token[data->j].quote_count = 1;
	data->j++;
}
