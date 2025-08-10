/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 14:23:40 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/22 15:26:34 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!f || !s)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void example_function(unsigned int index, char *c)
{
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main()
{
    char str[] = "hello world";
	printf("Origin: %s\n", str);
    ft_striteri(str, example_function);
    printf("Result: %s\n", str);
    return 0;
}*/
