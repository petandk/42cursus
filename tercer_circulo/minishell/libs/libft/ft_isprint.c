/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 12:50:52 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/15 15:25:06 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}
/*
int main(void)
{
    char test_char;

    printf("Ingresa un carácter: ");
    scanf("%c", &test_char);

    if (ft_isprint(test_char))
	{
        printf("El carácter '%c' es imprimible.\n", test_char);
    } 
	else
	{
        printf("El carácter '%c' no es imprimible.\n", test_char);
    }
    return 0;
}*/
