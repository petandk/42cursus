/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:34:48 by gpolo             #+#    #+#             */
/*   Updated: 2025/05/20 12:37:43 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	update_quotes(t_token_state *s, char c)
{
	if (c == '\'' && s->in_double == 0)
		s->in_single = !s->in_single;
	else if (c == '\"' && s->in_single == 0)
		s->in_double = !s->in_double;
}

static void	handle_operator(char *rl, int *i,
			t_token_state *s, int *tokens)
{
	if (s->in_token)
	{
		*tokens += 1;
		s->in_token = 0;
	}
	if ((rl[*i] == '>' && rl[*i + 1] == '>')
		|| (rl[*i] == '<' && rl[*i + 1] == '<'))
		*i += 1;
	*tokens += 1;
}

int	count_tokens(char *rl)
{
	t_token_state	s;
	int				i;
	int				tokens;

	s.in_single = 0;
	s.in_double = 0;
	s.in_token = 0;
	i = 0;
	tokens = 0;
	while (rl[i])
	{
		update_quotes(&s, rl[i]);
		if (s.in_single == 0 && s.in_double == 0 && ft_isspace(rl[i]))
			s.in_token = 0;
		else if (s.in_single == 0 && s.in_double == 0
			&& ft_strchr("<>|", rl[i]) != NULL)
			handle_operator(rl, &i, &s, &tokens);
		else if (s.in_token == 0)
		{
			tokens += 1;
			s.in_token = 1;
		}
		i += 1;
	}
	return (tokens);
}
