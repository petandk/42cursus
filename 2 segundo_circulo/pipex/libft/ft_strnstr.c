/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 15:35:36 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/01 15:14:47 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	aux;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (i < len && big[i])
	{
		aux = 0;
		while (big[i + aux] && big[i + aux] == little[aux] && i + aux < len)
		{
			aux++;
		}
		if (!little[aux])
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "lorem ipsum dolor sit amet";
	char *tofind = "dolor";
	char *result = ft_strnstr(str, tofind, 15);
	printf("%s", result);
	return (0);
}
*/
