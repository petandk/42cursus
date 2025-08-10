/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_var_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:11:48 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/11 18:04:53 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	index_value(t_quotes *quote, t_expan *ex)
{
	ex->start = ex->i + 1;
	while (quote[ex->j].quote_start != -1 || quote[ex->j].quote_end != -1)
	{
		if (ex->start <= quote[ex->j].quote_end)
			break ;
		if (quote[ex->j].quote_start == ex->i
			&& quote[ex->j].quote_end == ex->i)
			break ;
		if (ex->start == quote[ex->j].quote_start
			&& quote[ex->j].quote_start > quote[ex->j].quote_end)
			break ;
		ex->j++;
	}
}
