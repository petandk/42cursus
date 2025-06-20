/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:24:18 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/15 15:23:01 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')
		) || ((c >= '0') && (c <= '9')))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test_char;

    printf("Ingresa un carácter: ");
    scanf("%c", &test_char);

    if (ft_isalnum(test_char))
	{
        printf("El carácter '%c' es una letra o un numero.\n", test_char);
    } 
	else
	{
        printf("El carácter '%c' no es una letra o un numero.\n", test_char);
    }
    return 0;
}
*/
