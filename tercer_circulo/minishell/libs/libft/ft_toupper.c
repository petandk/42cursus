/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:13:44 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 15:54:41 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 97) && (c <= 122))
		return (c - 32);
	return (c);
}
/*
int	main(void)
{
	char test_char;

	printf("Ingresa un carácter; ");
	scanf("%c", &test_char);

	test_char = ft_toupper(test_char);
	printf("%c\n", test_char);
	return (0);
}
*/
