/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:01:00 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 15:56:23 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	char		*d;
	const char	*s;

	index = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    size_t index;
    size_t n;
    char dest[11] = "0123456789";
    char src[11] = "abcdefghij";

    n = 5;
    index = 0;
    ft_memcpy(dest, src, n);
    while (index++ < n)
        printf("%c ", dest[index - 1]);
    printf("\n");
    return 0;
}
*/
