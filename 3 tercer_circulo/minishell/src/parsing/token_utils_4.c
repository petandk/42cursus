/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:58:18 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/16 14:30:40 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_t(char *str, t_token **token, int size)
{
	free(str);
	free_token(token, size);
}

void	init_quote_tracker(t_quote_tracker *qt)
{
	qt->open_pos = -1;
	qt->current_len = 0;
	qt->active = 0;
}

int	finalize_token(t_token_data *data)
{
	int	i;

	if (data->str_i > 0 || (data->str_i == 0 && data->token[data->j].quotes
			&& data->token[data->j].quotes->closed))
	{
		data->str[data->str_i] = '\0';
		data->token[data->j].str = ft_strdup(data->str);
		data->j++;
	}
	i = check_unclosed_quotes(data, data->j);
	return (i);
}

void	process_token_loop(t_token_data *data, t_quote_tracker *qt, char *rl)
{
	while (rl[data->i])
	{
		data->c = rl[data->i];
		if (handle_quotes(data, qt))
			continue ;
		if (qt->active)
		{
			qt->current_len++;
			data->str[data->str_i++] = data->c;
			data->i++;
			continue ;
		}
		if (process_outside_quotes(data, rl))
			continue ;
		data->i++;
	}
	if (qt->active)
		register_unclosed_quote(data, qt);
}

void	handle_final_token(t_token_data *data, t_shell *shell)
{
	if (!finalize_token(data))
		execution(data->str, &data->token, data->size_token, shell);
	else
		free_t(data->str, &data->token, data->size_token);
}
