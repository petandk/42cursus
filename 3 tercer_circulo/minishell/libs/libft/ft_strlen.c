/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:57:32 by gpolo             #+#    #+#             */
/*   Updated: 2024/12/19 13:15:21 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s && s[c] != '\0')
		c++;
	return (c);
}
/*
int main() {
    char test_str[100];

    printf("Ingresa una cadena: ");
    fgets(test_str, sizeof(test_str), stdin);

    size_t len = ft_strlen(test_str);
    if (len > 0 && test_str[len - 1] == '\n') {
        test_str[len - 1] = '\0';
    }

    int length = ft_strlen(test_str);
    printf("La longitud de la cadena ingresada es: %d\n", length);

    return (0);
}*/
