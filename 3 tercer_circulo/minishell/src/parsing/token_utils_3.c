/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:01:16 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/03 14:33:59 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_string_array(char ***array, int size)
{
	int	i;

	if (!array || size <= 0)
		return ;
	*array = ft_calloc(size + 1, sizeof(char *));
	if (!*array)
		exit(1);
	i = 0;
	while (i < size)
	{
		(*array)[i] = NULL;
		i++;
	}
}

void	init_quote_array(t_quotes ***array, int size)
{
	int	i;

	if (!array || size <= 0)
		return ;
	*array = ft_calloc(size + 1, sizeof(t_quotes *));
	if (!*array)
		exit(1);
	i = 0;
	while (i < size)
	{
		(*array)[i] = NULL;
		i++;
	}
}

void	init_int_array(int **array, int size)
{
	int	i;

	if (!array || size <= 0)
		return ;
	*array = ft_calloc(size + 1, sizeof(int));
	if (!*array)
		exit(1);
	i = 0;
	while (i < size)
	{
		(*array)[i] = 0;
		i++;
	}
}

void	init_int_out(t_comand_data *comand, int size_in, int size_out)
{
	if (size_in > 0)
	{
		init_string_array(&comand->in_file, size_in);
		init_quote_array(&comand->quote_in, size_in);
		init_int_array(&comand->quote_in_count, size_in);
	}
	if (size_out > 0)
	{
		init_string_array(&comand->out_file, size_out);
		init_quote_array(&comand->quote_out, size_out);
		init_int_array(&comand->quote_out_count, size_out);
	}
}

void	in_out_size(t_comand_data *comand, t_ind ind,
			int size_token, t_token *token)
{
	comand->in_count = 0;
	comand->out_count = 0;
	while (ind.i < size_token && !token[ind.i].pipe)
	{
		if (!token[ind.i].str)
		{
			if (ind.i + 1 < size_token && token[ind.i + 1].str)
			{
				if (token[ind.i].greater_than || token[ind.i].double_greater)
					comand->out_count += 1;
				else if (token[ind.i].less_than || token[ind.i].double_less)
					comand->in_count += 1;
			}
		}
		ind.i++;
	}
}
