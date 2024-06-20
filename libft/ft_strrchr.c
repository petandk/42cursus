/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:18:48 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/19 15:29:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
		index++;
	while (index > 0)
	{
		if (s[index] == c)
			return ((char *)s + index);
		index--;
	}
	if (s[index] == c)
		return ((char *)s + index);
	return (NULL);
}
