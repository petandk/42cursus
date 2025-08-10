/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:36:03 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 16:51:18 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*result;

	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (start + len > s_len)
		len = s_len - start;
	result = malloc(sizeof(*s) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

/*int	main(int argc, char **argv)
{
	const char		*original_string;
	unsigned int	start_index;
	size_t			substring_length;
	char			*result;

	if (argc != 4)
		return (write (2, "Error", 50));
	original_string = argv[1];
	start_index = atoi(argv[2]);
	substring_length = atoi(argv[3]);
	result = ft_substr(original_string, start_index, substring_length);
	if (result)
	{
		printf("Cadena original: %s\n", original_string);
		printf("Subcadena desde el indice %u y", start_index);
		printf (" con longitud %zu: %s\n", substring_length, result);
		free(result);
	}
	else
	{
		printf("Fallo de asignacion de memoria o parametros invalidos.\n");
	}
	return (0);
}*/
