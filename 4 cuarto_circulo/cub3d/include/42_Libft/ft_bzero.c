/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:24:36 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:43:08 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

/*int	main(int argc, char **argv)
{
	size_t	longitud;

	if (argc != 3)
	{
		printf("Uso: %s <cadena> <caracter> <cantidad>\n", argv[0]);
		return (1);
	}

	longitud = atoi(argv[2]);
	printf("Antes de ft_bzero: %s\n", argv[1]);
	ft_bzero(argv[1], longitud);
	printf("Despues de ft_bzero: %s\n", argv[1]);
	return (0);
}*/
