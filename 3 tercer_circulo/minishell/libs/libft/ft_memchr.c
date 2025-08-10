/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:59:12 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 15:16:12 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (n > i)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	char_test[20] = "Hola! #G $F $a Polo.";
	char	*char_test2;
	char	c;
	size_t	n;

	printf("Cadena original: ");
	printf("%s\n", char_test);
	printf("Introduzaca carrcate a localizar: ");
	scanf("%c", &c);
	printf("Introduzaca un caracter tipo sise_t  inferior a 20 ");
	scanf("%zu", &n);

	if (ft_memchr(char_test, c, n) == NULL)
		printf("Caracter no enclontrado entre los %zu caraccteres.\n",n);
	else 
	{
		char_test2 = ft_memchr(char_test, c, n);
		printf("%s\n",char_test2);
	}
}*/
