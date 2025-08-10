/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:15:09 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/18 18:18:10 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	copy = malloc(ft_strlen((char *)str) + 1);
	if (copy != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			copy[i] = str[i];
			i++;
		}
		copy[i] = '\0';
		return (copy);
	}
	return (copy);
}

/*int	main(int argc, char *argv[])
{
	char	*original;
	char	*copy;

	if (argc < 2)
	{
		printf("Usage: %s <string>\n", argv[0]);
		return (1);
	}
	original = argv[1];
	copy = strdup(original);
	if (copy == NULL)
	{
		printf("Error al asignar memoria\n");
		return (1);
	}
	printf("Original: %s\n", original);
	printf("Copy: %s\n", copy);
	free(copy);
	return (0);
}*/
