/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:50:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/18 18:39:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = ft_strlen((char *)dest);
	src_len = ft_strlen((char *)src);
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	while (src[i] && ((dest_len + i + 1) < size))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len != size)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

/*int	main(int argc, char **argv)
{
	size_t	size;
	size_t	result;

	if (argc != 4)
		return (write (2, "Error", 5));
	size = (size_t)atoi(argv[3]);
	result = ft_strlcat(argv[1], argv[2], size);
	printf("Concatenado: '%s'\n", argv[1]);
	printf("Longitud total: %zu\n", result);
	return (0);
}*/
