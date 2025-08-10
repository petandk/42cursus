/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:59:16 by pamanzan          #+#    #+#             */
/*   Updated: 2024/06/17 17:24:16 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!s2[0])
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			while (s1[i + j] == s2[j] && s1[i + j] != '\0' && i + j < n)
			{
				if (s2[j + 1] == '\0')
					return ((char *)(s1 + i));
				j++;
			}
		}
		i++;
	}
	return (NULL);
}

/*int	main(int argc, char **argv)
{
	const char	*str1;
	const char	*str2;
	int			n;
	char		*result;

	if (argc != 4)
		return (write (2, "Error", 5));
	str1 = argv[1];
	str2 = argv[2];
	n = atoi(argv[3]);
	result = ft_strnstr(str1, str2, n);
	if (result)
	{
		printf("'%s' encontrado en '%s'.'\n", str2, str1);
		printf("Resultado: '%s'\n", result);
	}
	else
	{
		printf("'%s' no encontrado en '%s'.\n", str2, str1);
	}
	return (0);
}*/
