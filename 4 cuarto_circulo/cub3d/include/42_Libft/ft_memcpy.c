/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 08:02:26 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/01 14:54:20 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	if (dest == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*int	main(int argc, char **argv)
{
	char	dest[20];

	if (argc != 2)
	{
		printf("Uso: %s <cadena_origen> <cadena_destino>\n", argv[0]);
		return (1);
	}
	ft_memcpy(dest, argv[1], ft_strlen(argv[1]));
	printf("Copia: %s\n", dest);
	return (0);
}*/
