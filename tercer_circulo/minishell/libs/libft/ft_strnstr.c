/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:40:32 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 16:47:41 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	c;
	size_t	c2;

	c = 0;
	if (needle[c] == '\0')
		return ((char *)haystack);
	while ((haystack[c]) && (c < len))
	{
		c2 = 0;
		while ((haystack[c + c2]) && (needle[c2]) && ((c + c2) < len
			) && (haystack[c + c2] == needle[c2]))
		{
			if (needle[c2 + 1] == '\0')
				return ((char *)haystack + c);
			c2++;
		}
		c++;
	}
	return (0);
}
/*
int	main(void)
{
	char	char_test[20];
	char	*char_test2;
	char	char_test1[20];
	size_t		n;

	printf("Cadena original: ");
	if (fgets(char_test, sizeof(char_test), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	printf("Introduzaca cadena a localizar: ");
	if (fgets(char_test1, sizeof(char_test1), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}
	printf("Introduzaca un caracter tipo sise_t  inferior a 20 ");
	scanf("%zu", &n);

	if (ft_strnstr(char_test, char_test1, n) == NULL)
		printf("Caracter no enclontrado entre los %zu caraccteres.\n",n);
	else 
	{
		char_test2 = ft_strnstr(char_test, char_test1, n);
		printf("%s\n",char_test2);
	}
}*/
