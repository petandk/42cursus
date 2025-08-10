/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 11:50:56 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/15 15:22:36 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test_char;

    printf("Ingresa un carácter: ");
    scanf("%c", &test_char);

    if (ft_isalpha(test_char))
	{
        printf("El carácter '%c' es una letra.\n", test_char);
    } 
	else
	{
        printf("El carácter '%c' no es una letra.\n", test_char);
    }
    return 0;
}*/
