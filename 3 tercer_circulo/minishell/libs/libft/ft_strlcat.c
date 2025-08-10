/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 14:28:38 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 15:56:19 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	total_len;
	size_t	c;
	size_t	c2;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	total_len = dest_len + src_len;
	c = 0;
	c2 = 0;
	if (size <= dest_len)
		return (size + src_len);
	while ((src[c2]) && (c < size - dest_len - 1))
	{
		dest[dest_len + c] = src[c2];
		c++;
		c2++;
	}
	dest[dest_len + c] = '\0';
	return (total_len);
}
/*
int	main(void)
{
	char	src[20] = "Gyan Polo LLorens";
	char	dest[20] = "Hola ";
	size_t	size;

	printf("Cadena de origen: %s\n", src);
	printf("Cadena de destino: %s\n", dest);
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
	ft_strlcat(dest, src, size);
	printf("Cadena de destino después de ft_strlcat: %s\n", dest);
	return 0;
}*/
