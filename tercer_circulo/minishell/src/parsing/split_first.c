/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:58:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/17 13:05:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*ft_free(char **strings, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strings[i]);
		i++;
	}
	free(strings);
	return (NULL);
}

static char	*ft_fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = ft_calloc(end - start + 1, sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static int	word_count(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (2);
		str++;
	}
	return (1);
}

static char	**ft_fill_matrix(const char *s, char c, char **matrix)
{
	size_t	i;
	int		start;

	i = 0;
	start = 0;
	while (s[i] && s[i] != c)
		i++;
	matrix[0] = ft_fill_word(s, start, i);
	if (!matrix[0])
		return (ft_free(matrix, 0));
	if (s[i] == c)
	{
		matrix[1] = ft_fill_word(s, i + 1, ft_strlen(s));
		if (!matrix[1])
			return (ft_free(matrix, 1));
	}
	else
		matrix[1] = NULL;
	return (matrix);
}

char	**split_first(const char *s, char c)
{
	char	**matrix;

	if (!s)
		return (NULL);
	matrix = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	if (!matrix)
		return (NULL);
	return (ft_fill_matrix(s, c, matrix));
}
