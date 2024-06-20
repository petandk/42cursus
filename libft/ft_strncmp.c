/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:30:15 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/19 15:53:31 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}
/*
int	main(void)
{
	char *str1 = "hola que tal";
	char *str2 = "hola que tal";
	char *str3 = "hola como estas";
	char *str4 = "";
	printf("str1 vs str2 (eq expected): %d\n", ft_strncmp(str1, str2, 12));
	printf("str1 vs str3 (str3 bigger): %d\n", ft_strncmp(str1, str3, 12));
	printf("str1 vs str3 (eq expected): %d\n", ft_strncmp(str1, str2, 5));
	printf("str3 vs str4 (str4 bigger): %d\n", ft_strncmp(str3, str4, 12));
	printf("str3 vs str1 (str3 bigger): %d\n", ft_strncmp(str3,str1,12));

	return (0);
}
*/
