/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:39:07 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/17 16:46:47 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

/*int	main(int argc, char **argv)
{
	char	result;

	if (argc != 2)
		return (write (2, "Error", 5));
	result = ft_strlen(argv[1]);
	printf("La cadena %s, tiene un size de %d\n", argv[1], result);
	return (0);
}*/
