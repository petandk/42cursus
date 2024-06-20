/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:55:27 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/18 15:55:31 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		d += (n - 1);
		s += (n - 1);
		while (n--)
			*d-- = *s--;
	}
	return (dest);
}
/*
#include <string.h>

int main() {
    // Test without overlap
    char src[] = "Hello, World!";
    char dest[] = "Goodbye, World!";
    ft_memmove(dest, src, 14);
    printf("Without overlap: %s\n", dest);
    
	// Test with overlap
    char src2[] = "Hello, World!";
    char dest2[] = "Hello, World!";
    ft_memmove(dest2 + 5, src2, 14);
    printf("With overlap: %s\n", dest2);

    return 0;
}
*/
