/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:32:08 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 13:47:56 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	c;

	if (!dest && !src)
		return (0);
	if (dest < src)
	{
		c = 0;
		while (c < n)
		{
			((unsigned char *)dest)[c] = ((unsigned char *)src)[c];
			c++;
		}
	}
	else if (src < dest)
	{
		c = 0;
		while (0 < n)
		{
			n--;
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
		}
	}
	return (dest);
}
/*
int main()
{
	char	src[20] = "Hello, World!";
	char	dest[20];
	size_t	n;

	printf("Cadena de origen: %s\n", src);
	printf("Ingresa un valor de tipo size_t para copiar (inferior a 20): ");
	if (scanf("%zu", &n) != 1)
	{
		printf("Error al leer el valor.\n");
		return 1;
	}

	if (n > 20)
	{
		printf("El valor de n debe ser inferior a 20.\n");
		return 1;
	}

	ft_memmove(dest, src, n);
	dest[n] = '\0';
	printf("Cadena de destino después de ft_memmove
	(no superpuesta): %s\n", dest);

	ft_memmove(src + 5, src, n);
	printf("Cadena de origen después de ft_memmove (superpuesta): %s\n", src);

	return 0;
}*/
