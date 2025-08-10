/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:49:43 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 14:26:35 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	cap;
	size_t	c;

	cap = 0;
	c = 0;
	while (src[cap])
		cap++;
	if (size < 1)
		return (cap);
	while (src[c] && size - 1 > 0)
	{
		dest[c] = src[c];
		c++;
		size--;
	}
	dest[c] = '\0';
	return (cap);
}
/*
int	main(void)
{
	char	src[20] = "Gyan Polo LLorens";
	char	dest[20];
	size_t	size;

	printf("Cadena de origen: %s\n", src);
	printf("Ingresa un valor de tipo size_t para copiar (inferior a 20): ");
	if (scanf("%zu", &size) != 1)
	{
		printf("Error al leer el valor.\n");
		return (1);
	}
	if (size > 20)
	{
		printf("El valor de size debe ser inferior a 20.\n");
		return (1);
	}
	ft_strlcpy(dest, src, size);
	printf("Cadena de destino después de ft_strlcpy: %s\n", dest);
	return 0;
}*/
