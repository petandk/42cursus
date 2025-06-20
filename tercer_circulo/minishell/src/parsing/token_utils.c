/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:37:18 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/11 13:14:29 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	if ((c == 32) || ((c >= 9) && (c <= 13)))
		return (1);
	else
		return (0);
}

void	token_operator(t_token *token, char c, char next)
{
	token->str = NULL;
	if (c == '>' && next == '>')
		token->double_greater = 1;
	else if (c == '<' && next == '<')
		token->double_less = 1;
	else if (c == '>')
		token->greater_than = 1;
	else if (c == '<')
		token->less_than = 1;
	else if (c == '&')
		token->pipe = -1;
	else if (c == '|')
		token->pipe = 1;
}

void	init_token(t_token *token, int size, int num_quotes)
{
	int	i;
	int	q;

	i = 0;
	while (i < size)
	{
		token[i].str = NULL;
		token[i].greater_than = 0;
		token[i].double_greater = 0;
		token[i].less_than = 0;
		token[i].double_less = 0;
		token[i].pipe = 0;
		token[i].quotes = ft_calloc(num_quotes + 1, sizeof(t_quotes));
		q = 0;
		while (q < num_quotes)
		{
			token[i].quotes[q].quote = 0;
			token[i].quotes[q].quote_start = -1;
			token[i].quotes[q].quote_end = -1;
			q++;
		}
		token[i].quote_count = 0;
		i++;
	}
}

void	free_token(t_token **token, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if ((*token)[i].quotes)
			free((*token)[i].quotes);
		if ((*token)[i].str)
			free((*token)[i].str);
		i++;
	}
	free(*token);
}

int	init_all(t_token_data *data, char *rl)
{
	int	num_quotes;

	num_quotes = count_quotes(rl, 0, 0, 0);
	data->i = 0;
	data->j = 0;
	data->str_i = 0;
	data->size_token = count_tokens(rl);
	if (data->size_token == -1)
	{
		ft_putendl_fd("Error: Incorrect redirection operators.", 2);
		return (0);
	}
	if (data->size_token == 0)
		return (0);
	data->str = ft_calloc(ft_strlen(rl) + 1, sizeof(char));
	if (!data->str)
		return (0);
	data->token = ft_calloc(data->size_token + 1, sizeof(t_token));
	if (!data->token)
	{
		free(data->str);
		return (0);
	}
	init_token(data->token, data->size_token, num_quotes);
	return (1);
}
