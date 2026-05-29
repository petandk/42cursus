/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:43:55 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:52:53 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	index;

	index = 0;
	while (s[index])
	{
		f(index, &s[index]);
		index++;
	}
}
/*
#include <stdio.h>
void to_upper(unsigned int i, char *c)
{
	printf("%d\n", i);
	if(*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	char str[] = "Hello, World!";
	ft_striteri(str, &to_upper);
	printf("result: %s\n", str);
	return (0);
}
*/
