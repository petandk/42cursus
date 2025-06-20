/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 09:55:19 by gpolo             #+#    #+#             */
/*   Updated: 2024/08/26 14:44:04 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	n_splits(char const *s, char c)
{
	size_t	splits;

	splits = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			splits++;
			while (*s && *s != c)
				s++;
		}
	}
	return (splits);
}

char	*alloc_and_copy(char const *s, size_t len)
{
	char	*sub;
	size_t	j;

	j = 0;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (0);
	while (j < len)
	{
		sub[j] = s[j];
		j++;
	}
	sub[len] = '\0';
	return (sub);
}

char	**free_all(char **result, size_t i)
{
	while (i > 0)
	{
		free(result[--i]);
	}
	free(result);
	return (0);
}

char	**fill_result(char const *s, char c, char **result)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			len = 0;
			while ((s[len]) && (s[len] != c))
				len++;
			result[i] = alloc_and_copy(s, len);
			if (!result[i])
				return (free_all(result, i));
			i++;
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	splits;

	splits = n_splits(s, c);
	result = (char **)malloc((splits + 1) * sizeof(char *));
	if (!result)
		return (0);
	return (fill_result(s, c, result));
}
/*
int main(void) {
    char str[50] ;
    char delimiter ;
    char **split_result;
    size_t i;

	printf("Ingresa una cadena original: ");
	if (fgets(str, sizeof(str), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	printf("Ingresa un delimitador: ");
	scanf("%c",&delimiter);

    split_result = ft_split(str, delimiter);
    if (!split_result) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    i = 0;
    while (split_result[i]) {
        printf("Split result [%zu]: %s\n", i, split_result[i]);
        free(split_result[i]);
        i++;
    }
    free(split_result);

    return 0;
}*/
