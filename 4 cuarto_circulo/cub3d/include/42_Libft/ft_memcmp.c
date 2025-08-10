/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:47:37 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/15 16:45:18 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/*int	main(int argc, char **argv)
{
	char	*str1;
	char	*str2;
	int		result;

	if (argc != 3)
		return (write (2, "Error", 5));
	str1 = argv[1];
	str2 = argv[2];
	result = memcmp(str1, str2, ft_strlen(str1));
	if (result > 0)
	{
		write(1, "str2 es menor que str1", 23);
	}
	else if (result < 0)
	{
		write (1, "str1 es menor que str2", 23);
	}
	else if (result == 0)
	{
		write (1, "str1 es igual a str2", 23);
	}
	return (0);
}*/
