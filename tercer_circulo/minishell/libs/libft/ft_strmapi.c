/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:32:56 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/28 16:52:19 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (0);
	result = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!result)
		return (0);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
char example_function(unsigned int index, char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

int main()
{
	char *str = "hello world";
	char *result = ft_strmapi(str, example_function);

	if (result)
	{
		printf("Original: %s\n", str);
		printf("Result: %s\n", result);
		free(result);
	}
	else
	{
		printf("Error: Memoria no asignada\n");
	}

	return 0;
}*/
