/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:26:46 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:54:49 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*str;

	index = 0;
	str = (unsigned char *)s;
	while (index < n)
	{
		str[index] = c;
		index++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "hola que tal";
	char *str_ptr = str;
	ft_memset(str_ptr, 'a', 4);
	printf("%s\n",str);
	return (0);
}
*/
