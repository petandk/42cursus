/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:12:48 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:03 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("ft_tolower of a = %c\n", ft_tolower('a'));
	printf("ft_tolower of A = %c\n", ft_tolower('A'));
	printf("ft_tolower of 1 = %c\n", ft_tolower('1'));
	printf("ft_tolower of @ = %c\n", ft_tolower('@'));
	printf("ft_tolower of   = %c\n", ft_tolower(' '));
	return (0);
}
*/
