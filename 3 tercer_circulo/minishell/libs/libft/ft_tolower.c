/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 15:55:44 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 15:58:55 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 65) && (c <= 90))
		return (c + 32);
	return (c);
}
/*
int	main(void)
{
	char test_char;

	printf("Ingresa un carácter; ");
	scanf("%c", &test_char);

	test_char = ft_tolower(test_char);
	printf("%c\n", test_char);
	return (0);
}
*/
