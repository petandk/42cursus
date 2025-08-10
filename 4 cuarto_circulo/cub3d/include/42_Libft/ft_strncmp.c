/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:49:52 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/17 16:58:10 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && *s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	else
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
}

/*int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	int		n;
	int		result;

	if (argc != 4)
		return (write (2, "Error", 5));
	str1 = argv[1];
	str2 = argv[2];
	n = atoi(argv[3]);
	result = strncmp(str1, str2, n);
	if (result > 0)
	{
		write (1, "str2 es menor que str1", 23);
	}
	else if (result < 0)
	{
		write (1, "str1 es menor que str2", 23);
	}
	else
	{
		write (1, "str1 es igual a str2", 23);
	}
	return (0);
}*/
