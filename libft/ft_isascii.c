/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:36:14 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:58:57 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>

int main(void)
{
	int c;

	c = 'A';
	printf("ft_isascii(%c) = %d\n", c, ft_isascii(c));

	c = 'a';
	printf("ft_isascii(%c) = %d\n", c, ft_isascii(c));

	c = '0';
	printf("ft_isascii(%c) = %d\n", c, ft_isascii(c));

	c = '@';
	printf("ft_isascii(%c) = %d\n", c, ft_isascii(c));

	c = 600;
	printf("ft_isascii(%c) = %d\n", c, ft_isascii(c));
	return (0);
}
*/
