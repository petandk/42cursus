/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:43:27 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 19:53:44 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0) && (c <= 127))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test_char;

    printf("Ingresa un carácter: ");
    scanf("%c", &test_char);

    if (ft_isascii(test_char))
	{
        printf("El carácter '%c' es ascci.\n", test_char);
    } 
	else
	{
        printf("El carácter '%c' no es ascci.\n", test_char);
    }
    return 0;
}
*/
