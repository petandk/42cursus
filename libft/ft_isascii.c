/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:36:14 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/18 16:03:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
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
