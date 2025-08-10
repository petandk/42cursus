/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:55:46 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/28 16:36:38 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	len;
	size_t	end;

	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	len = end - start;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1 + start, len);
	result[len] = '\0';
	return (result);
}
/*
int main(void)
{
    char str[50] ;
    char set[10] ;

	printf("Ingresa una cadena original: ");
	if (fgets(str, sizeof(str), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	printf("Ingresa una cadena para set:  ");
	if (fgets(set, sizeof(set), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}

    char *trimmed = ft_strtrim(str, set);
    if (trimmed)
    {
        printf("Original: '%s'\n", str);
        printf("Trimmed: '%s'\n", trimmed);
        free(trimmed);
    }
    else
    {
        printf("Error: Memory allocation failed\n");
    }

    return 0;
}*/
