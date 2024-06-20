/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:35:36 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/20 16:17:41 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	tofindlen;
	size_t	aux;

	index = 0;
	tofindlen = 0;
	while (little[tofindlen])
		tofindlen++;
	if (tofindlen == 0)
		return ((char *)big);
	while (index < len && big[index])
	{
		aux = 0;
		while (big[index + aux] == little[aux] && index + aux < len)
		{
			aux++;
		}
		if (aux == tofindlen)
			return ((char *)big + index);
		index++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *str = "lorem ipsum dolor sit amet";
	char *tofind = "dolor";
	char *result = ft_strnstr(str, tofind, 15);
	printf("%s", result);
	return (0);
}
*/
