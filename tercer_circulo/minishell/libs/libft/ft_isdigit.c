/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:19:08 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/21 14:39:59 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test_char;

    printf("Ingresa un carácter: ");
    scanf("%c", &test_char);

    if (ft_isdigit(test_char))
	{
        printf("El carácter '%c' es un digito.\n", test_char);
    } 
	else
	{
        printf("El carácter '%c' no es un digito.\n", test_char);
    }
    return 0;
}*/
