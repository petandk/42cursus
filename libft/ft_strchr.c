/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:18:22 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/19 13:33:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
int	main(void)
{
	char *str = "";
	printf("%s\n", ft_strchr(str, '\0'));
	return (0);
}
*/
