/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:42:07 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/14 18:35:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int main(void)
{
	char c;

	c = 'A';
	printf("ft_isalnum(%c) = %d\n", c, ft_isalnum(c));

	c = 'a';
	printf("ft_isalnum(%c) = %d\n", c, ft_isalnum(c));

	c = '0';
	printf("ft_isalnum(%c) = %d\n", c, ft_isalnum(c));

	c = '@';
	printf("ft_isalnum(%c) = %d\n", c, ft_isalnum(c));

	return (0);
}
*/
