/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:52:43 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 16:31:47 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
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

	if (ft_strrchr(char_test, c) == NULL)
		printf("Caracter no enclontrado.\n");
	else 
	{
		char_test2 = ft_strrchr(char_test, c);
		printf("%s\n",char_test2);
	}
}
*/
