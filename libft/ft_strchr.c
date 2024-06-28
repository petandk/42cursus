/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:18:22 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:30:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == c)
			return ((char *)s + index);
		index++;
	}
	if (s[index] == c)
		return ((char *)s + index);
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "";
	printf("%s\n", ft_strchr(str, '\0'));
	return (0);
}
*/
