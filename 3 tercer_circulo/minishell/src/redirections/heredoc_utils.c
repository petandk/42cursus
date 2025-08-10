/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:12:39 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/01 13:29:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_calculate_size(const char *str)
{
	size_t	size;

	if (!str)
		return (0);
	size = ft_strlen(str) + 1;
	if (ft_strstr(str, " << "))
		size -= 3;
	if (ft_strstr(str, "<<"))
		size -= 1;
	return (size);
}

static void	ft_handle_heredoc(const char *str, int *i, int *j, char *result)
{
	if (str[*i] == ' ' && str[*i + 1] == '<'
		&& str[*i + 2] == '<' && str[*i + 3] == ' ')
	{
		result[*j] = '<';
		*i += 4;
		(*j)++;
	}
	else if (str[*i] == '<' && str[*i + 1] == '<')
	{
		result[*j] = '<';
		*i += 2;
		(*j)++;
	}
	else
	{
		result[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
}

static void	ft_handle_string(const char *str, char *result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		ft_handle_heredoc(str, &i, &j, result);
	result[j] = '\0';
}

char	*ft_replace(const char *str)
{
	size_t	size;
	char	*result;

	if (!str)
		return (NULL);
	size = ft_calculate_size(str);
	result = ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	ft_handle_string(str, result);
	return (result);
}

void	clean_heredoc(t_heredoc *vars)
{
	if (!vars)
		return ;
	if (vars->helper)
		free(vars->helper);
	if (vars->line)
		free(vars->line);
	free(vars);
}
