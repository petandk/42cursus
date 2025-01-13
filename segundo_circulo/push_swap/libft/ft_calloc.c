/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:36:45 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:59:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*buff;
	size_t			i;

	buff = (unsigned char *)malloc(sizeof (char) * (size * nmemb));
	if (!buff)
		return (NULL);
	i = 0;
	if (nmemb > 0)
	{
		while (i < nmemb * size)
			buff[i++] = 0;
	}
	return (buff);
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned char *str = (unsigned char *)ft_calloc(10, 5);
	if (!str)
	{
		printf("Memory allocation failed.\n");
		return (1);
	}
	printf("Allocated memory: %.*s\n", 10*5, str);
	free(str);
	return (0);
}
*/
