/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:48:26 by pamanzan          #+#    #+#             */
/*   Updated: 2024/07/02 08:41:47 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

/*int	main(int argc, char **argv)
{
	char	*result;

	if (argc != 3)
		return (write (2, "Error", 5));
	result = ft_strjoin(argv[1], argv[2]);
	if (result)
	{
		printf("Cadena concatenada: %s\n", result);
		free(result);
	}
	else
		printf("Error al reservar memoria.\n");
	return (0);
}*/
