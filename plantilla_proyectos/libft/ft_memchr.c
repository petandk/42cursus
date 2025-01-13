/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:16:43 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:57:16 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*spt;

	index = 0;
	spt = (unsigned char *)s;
	while (index < n)
	{
		if (spt[index] == (unsigned char) c)
			return ((void *)spt + index);
		index++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	char str[] = "Hello, World!";
	char *result;

	result = ft_memchr(str,'W', sizeof(str));
	if (result)
		printf("Found W at position: %ld\n", result - str);
	else
		printf("Character not found\n");
	return (0);
}
*/
