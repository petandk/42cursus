/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:48 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 15:10:14 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	while (index > 0)
	{
		if (s[index] == (unsigned char)c)
			return ((char *)s + index);
		index--;
	}
	if (s[index] == (unsigned char)c)
		return ((char *)s + index);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "Hello, World!";
	char *res = ft_strrchr(str, 'l');
	printf("Last 'l' in '%s' is at: %s\n", str, res);
	return (0);
}
*/
