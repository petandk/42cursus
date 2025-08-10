/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:46:04 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:11:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str = "Hello world!";
	char	*str2 = "123 hola 456 @";
	printf("Lenghth of '%s': %zu\n", str, ft_strlen(str));
	printf("Lenghth of '%s': %zu\n", str2, ft_strlen(str2));
}
*/
