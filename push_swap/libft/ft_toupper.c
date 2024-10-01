/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:09:59 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:25:27 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("ft_toupper of a = %c\n", ft_toupper('a'));
	printf("ft_toupper of A = %c\n", ft_toupper('A'));
	printf("ft_toupper of 1 = %c\n", ft_toupper('1'));
	printf("ft_toupper of @ = %c\n", ft_toupper('@'));
	printf("ft_toupper of   = %c\n", ft_toupper(' '));
	return (0);
}
*/
