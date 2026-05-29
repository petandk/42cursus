/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:25:37 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:58:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
#include <stdio.h>

int	main(void) 
{
	int	index;

	index = 0;
    while (index <= 255) 
    {
        printf("%c is %sprintable\n", index, ft_isprint(index) ? "" : "not ");
    	index++;
    }
    return (0);
}
*/
