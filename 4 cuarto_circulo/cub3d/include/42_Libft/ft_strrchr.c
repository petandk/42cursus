/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:41:12 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/18 19:09:48 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = ft_strlen(ptr) - 1;
	while (i >= 0)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i--;
	}
	if (c == '\0')
		return (ptr + ft_strlen(ptr));
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	const char	*cadena;
	char		caracter;
	char		*resultado;

	if (argc != 3)
		return (write (2, "Error", 5));
	cadena = argv[1];
	caracter = argv[2][0];
	resultado = ft_strrchr(cadena, caracter);
	if (resultado)
	{
		printf ("Ultima aparicion de '%c'", caracter);
		printf (" en la cadena '%s'.", cadena);
		printf ("Esta en la posicion: %ld\n", resultado - cadena);
	}
	else
	{
		printf ("'%c' no se encuentra en la cadena '%s'.\n", caracter, cadena);
	}
	return (0);
}*/
