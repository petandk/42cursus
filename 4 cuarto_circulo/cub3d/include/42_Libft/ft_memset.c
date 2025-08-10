/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 09:12:50 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/16 09:24:55 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr = (char)c;
		ptr++;
		n--;
	}
	return (s);
}

/*int	main(int argc, char *argv[])
{
	int	c;
	int	n;

	if (argc != 4)
	{
		printf ("Uso: %s <cadena> <caracter> <cantidad>\n", argv[0]);
		return (1);
	}
	c = argv[2];
	n = atoi(argv[3]);
	printf ("Antes de memset: %s\n", argv[1]);
	memset(argv[1], c, n);
	printf("Después de memset: %s\n", argv[1]);
	return (0);
}*/
