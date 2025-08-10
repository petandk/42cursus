/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:15:13 by gpolo             #+#    #+#             */
/*   Updated: 2025/06/11 16:59:18 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*init_str(char *c, t_token *token, int i, int size_token)
{
	char	*str;

	if (!c || !token || i + 1 >= size_token || !token[i + 1].str)
		return (NULL);
	str = ft_strjoin(c, token[i + 1].str);
	if (!malloc_test((void *)str))
		exit (1);
	return (str);
}

void	in_out_file(char **file, char *str)
{
	char	*tmp;

	if (file && *file)
	{
		tmp = ft_strjoin(*file, str);
		if (!malloc_test((void *)tmp))
			exit(1);
		free (*file);
		*file = ft_strdup(tmp);
		if (!malloc_test((void *)file))
			exit(1);
		free (tmp);
	}
	else
	{
		*file = ft_strdup(str);
		if (!malloc_test((void *)*file))
			exit(1);
	}
}

void	init_comand(t_comand_data *comand, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		comand[i].comand = NULL;
		comand[i].in_file = NULL;
		comand[i].out_file = NULL;
		comand[i].heredoc_fd = NULL;
		comand[i].n_heredocs = 0;
		comand[i].quote = NULL;
		comand[i].quote_in = NULL;
		comand[i].quote_out = NULL;
		comand[i].quote_count = NULL;
		comand[i].quote_in_count = NULL;
		comand[i].quote_out_count = NULL;
		comand[i].in_count = 0;
		comand[i].out_count = 0;
		i++;
	}
}

void	init_others(t_comand_data *comand, int j, int size)
{
	int	i;
	int	q;

	i = 0;
	while (i < size)
	{
		if (comand[j].quote && comand[j].quote[i])
		{
			q = 0;
			while (q < comand[j].quote_count[i])
			{
				comand[j].quote[i][q].quote = 0;
				comand[j].quote[i][q].quote_start = 0;
				comand[j].quote[i][q].quote_end = 0;
				q++;
			}
		}
		i++;
	}
	comand[j].in_count = 0;
	comand[j].out_count = 0;
}

int	count_comands(t_token *token, int size_token)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (i < size_token)
	{
		if (token[i].pipe)
			count++;
		if (token[i].pipe == -1)
			return (-1);
		i++;
	}
	return (count);
}
