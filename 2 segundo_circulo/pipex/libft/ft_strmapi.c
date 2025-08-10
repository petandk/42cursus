/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:03:54 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 15:00:38 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		index;
	char	*aux;

	index = 0;
	aux = ft_strdup(s);
	if (!aux)
		return (NULL);
	while (s[index])
	{
		aux[index] = f(index, s[index]);
		index++;
	}
	return (aux);
}
/*
#include <stdio.h>

char	to_upper(unsigned int i, char c)
{
	printf("character pos: %i is %c\n", i, c);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	char	*str = "Hello, World!";
	char	*result = ft_strmapi(str, &to_upper);
	if (result)
	{
		printf("Modified string %s\n", result);
		free(result);
	}
	else
		printf("Error: ft_strmapi returned NULL");
	return (0);
}
*/
