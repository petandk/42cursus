/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:59:53 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 16:12:56 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}
/*
int	main(void)
{
	char	char_test[20] = "Hola! #G $F $a Polo.";
	char	*char_test2;
	char	c;

	printf("Cadena original: ");
	printf("%s\n", char_test);
	printf("Introduzaca carrcate a localizar: ");
	scanf("%c", &c);

	if (ft_strchr(char_test, c) == NULL)
		printf("Caracter no enclontrado.\n");
	else 
	{
		char_test2 = ft_strchr(char_test, c);
		printf("%s\n",char_test2);
	}
}*/
