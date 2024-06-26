/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:48:48 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/26 12:05:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	index;

	subs = (char *)malloc(len + 1 * sizeof(char));
	if (!subs)
		return (NULL);
	index = 0;
	while (s[start + index] && index < len)
	{
		subs[index] = s[start + index];
		index++;
	}
	subs[index] = '\0';
	return (subs);
}
/*
int	main(void)
{
	char	*string = "Hola que tal estas?";
	char	*sub = ft_substr(string, 13, 6);
	printf("cadena esperada: \"estas?\"\ncadena devuelta: %s", sub);
	return (0);
}
*/
