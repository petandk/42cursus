/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:02:03 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/14 17:22:41 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int	isupper;
	int	islower;

	isupper = (c >= 65 && c <= 90);
	islower = (c >= 97 && c <= 122);
	return (isupper || islower);
}
/*
#include <stdio.h>

int main(void)
{
	char c;

	c = 'A';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));

	c = 'a';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));

	c = '0';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));

	c = '@';
	printf("ft_isalpha(%c) = %d\n", c, ft_isalpha(c));

	return (0);
}
*/
