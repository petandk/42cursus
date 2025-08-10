/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 09:39:43 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:44:28 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int	main(int argc, char **argv)
{
	const char	*cadena;
	char		c;
	char		*resultado;

	if (argc != 3)
		return (write (2, "Error", 5));
	cadena = argv[1];
	c = argv[2][0];
	resultado = ft_strchr(argv[1], c);
	if (resultado != NULL)
	{
		printf ("Caracter %c encontrado\n", c);
		printf ("en la posicion %ld\n", resultado - cadena);
	}
	else
	{
		printf ("Caracter %c no encontrado en la cadena %s.\n", c, cadena);
	}
	return (0);
}*/
