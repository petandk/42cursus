/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:26:57 by gpolo             #+#    #+#             */
/*   Updated: 2025/02/25 12:25:55 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				c;

	c = 0;
	if (!dest && !src)
		return (NULL);
	while (c < n)
	{
		((unsigned char *) dest)[c] = ((unsigned char *) src)[c];
		c++;
	}
	return (dest);
}
/*
int main()
{
	char	src[20];
	char	dest[20];
	size_t	n;

	printf("Ingresa una cadena de origen (máximo 19 caracteres): ");
	if (fgets(src, sizeof(src), stdin) == NULL)
	{
		printf("Error al leer la cadena.\n");
		return 1;
	}

	src[strcspn(src, "\n")] = '\0';

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

	ft_memcpy(dest, src, n);
	dest[n] = '\0';

	printf("Cadena de origen: %s\n", src);
	printf("Cadena de destino después de ft_memcpy: %s\n", dest);

	return 0;
}*/
