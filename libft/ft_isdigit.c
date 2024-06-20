/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:02:03 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/14 17:38:39 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>

int main(void)
{
	char c;

	c = 'A';
	printf("ft_isdigit(%c) = %d\n", c, ft_isdigit(c));

	c = 'a';
	printf("ft_isdigit(%c) = %d\n", c, ft_isdigit(c));

	c = '0';
	printf("ft_isdigit(%c) = %d\n", c, ft_isdigit(c));

	c = '@';
	printf("ft_isdigit(%c) = %d\n", c, ft_isdigit(c));

	return (0);
}
*/
