/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:56:29 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/18 17:05:36 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		uc;
	size_t				i;

	p = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (p[i] == uc)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
/*int	main(int argc, char **argv)
{
	const char	*cadena;
	int			caracter;
	int			n;
	char		*resultado;

	if (argc != 4)
		return (write (2, "Error", 5));
	cadena = &argv[1][0];
	caracter = argv[2][0];
	n = atoi(&argv[3][0]);
	resultado = ft_memchr(cadena, caracter, n);
	if (resultado != NULL)
	{
		printf("Caracter '%c' encontrado en '%s'.\n", caracter, cadena);
		printf("dentro de los primeros '%d' bytes.", n);
	}
	else
	{
		printf("Caracter no encontrado");
	}
	return (0);
}*/
