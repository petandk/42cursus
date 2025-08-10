/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:02:45 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/19 15:25:29 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	char	*result;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1) != NULL)
		s1++;
	len = ft_strlen((char *)s1);
	while (len && ft_strchr(set, s1[len - 1]) != NULL)
		len--;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

/*int	main(int argc, char *argv[])
{
	char	*s1;
	char	*set;
	char	*resultado;

	if (argc != 3)
	{
		return (write (2, "Error", 5));
	}
	s1 = argv[1];
	set = argv[2];
	resultado = ft_strtrim(s1, set);
	if (resultado)
	{
		printf("Cadena resultante: '%s'\n", resultado);
		free(resultado);
	}
	else
		printf("No se pudo asignar memoria o los argumentos eran inválidos.\n");
	return (0);
}*/
