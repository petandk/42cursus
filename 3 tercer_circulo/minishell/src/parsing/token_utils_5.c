/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:00:10 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/11 18:12:37 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	start_quote(t_token_data *data, t_quote_tracker *qt,
			t_token *curr_token)
{
	int	idx;

	idx = curr_token->quote_count;
	curr_token->quotes[idx].quote_start = data->str_i;
	curr_token->quotes[idx].quote_end = -1;
	curr_token->quotes[idx].closed = 0;
	if (data->c == '\'')
	{
		curr_token->quotes[idx].quote = 1;
		qt->active = 1;
	}
	else
	{
		curr_token->quotes[idx].quote = 2;
		qt->active = 2;
	}
	curr_token->quote_count++;
	qt->open_pos = data->str_i;
}

void	end_quote(t_token_data *data, t_quote_tracker *qt, t_token *curr_token)
{
	int	idx;

	idx = curr_token->quote_count - 1;
	curr_token->quotes[idx].quote_end = data->str_i - 1;
	curr_token->quotes[idx].closed = 1;
	qt->active = 0;
}

int	check_unclosed_quotes(t_token_data *data, int token_count)
{
	int		tok_i;
	int		q_i;
	t_token	*curr_token;

	tok_i = 0;
	while (tok_i < token_count)
	{
		curr_token = &data->token[tok_i];
		q_i = 0;
		while (q_i < curr_token->quote_count)
		{
			if (!curr_token->quotes[q_i].closed)
			{
				ft_putendl_fd("No closed quotes", 2);
				return (1);
			}
			q_i++;
		}
		tok_i++;
	}
	return (0);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*join;

	join = ft_strjoin(s1, s2);
	free(s1);
	return (join);
}

int	is_in_single_quote(int i, t_quotes *quotes)
{
	int	j;

	if (!quotes)
		return (0);
	j = 0;
	while (quotes[j].quote_start != -1)
	{
		if (quotes[j].quote == 1
			&& i >= quotes[j].quote_start && i <= quotes[j].quote_end)
			return (1);
		j++;
	}
	return (0);
}
