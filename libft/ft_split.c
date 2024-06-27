/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:16:50 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/27 16:09:37 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(char **strings, int count)
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
	word = (char *)malloc((end - start + 1) * sizeof(char));
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
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (count);
}

static char	**ft_fill_matrix(const char *s, char c, char **matrix)
{
	size_t	i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	start = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || i == ft_strlen(s)) && start >= 0)
		{
			matrix[j] = ft_fill_word(s, start, i);
			if (!(matrix[j]))
				return (ft_free(matrix, j));
			start = -1;
			j++;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(const char *s, char c)
{
	char	**matrix;

	matrix = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	return (ft_fill_matrix(s, c, matrix));
}
/*
// to compile: cc -Wall -Werror -Wextra ft_split.c ft_calloc.c ft_strlen.c
int	main(int argc, char *argv[])
{
	int	i;
	
	i = 0;
	if (argc != 3)
	{
		printf("3 arguments needed");
		return (1);
	}
	char **matrix = ft_split(argv[1], argv[2][0]);
	if (!matrix)
	{
		printf("Error:ft_split falied \n");
		return (1);
	}
	printf("the sentence: %s\n separated by: %c\n",argv[1], argv[2][0]);
	while (matrix[i])
	{
		printf("%i: %s\n", i + 1, matrix[i]);
		i++;
	}
	ft_free(matrix, i);
	return (0);
}
*/
