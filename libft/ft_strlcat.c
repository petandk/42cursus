/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:45:27 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/18 18:57:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	index;

	dlen = 0;
	slen = 0;
	index = 0;
	while (dlen < size && dst[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if (size - dlen < 1)
		return (dlen + slen);
	while (index < slen && dlen + index < size - 1)
	{
		dst[dlen + index] = src[index];
		index++;
	}
	dst[dlen + index] = '\0';
	return (dlen + slen);
}
/*
int	main(void)
{
	char	dest[11] = "a";
	ft_strlcat(dest, "ipsum", 15);
	printf("%s\n", dest);
	char	dest2[11] = "a";
	ft_strlcat(dest2, "lorem ipsum", 15);
	printf("%s\n", dest2);
	char	dest3[14] = "a";
	ft_strlcat(dest3, "lorem ipsum dolor sit amet", 15);
	printf("%s\n", dest3);
	return (0);
}
*/
