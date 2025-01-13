/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:38:07 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 16:05:07 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	slen;

	index = 0;
	slen = 0;
	while (src[slen])
		slen++;
	if (size == 0)
		return (slen);
	while (index < size - 1 && index < slen)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (slen);
}
/*
#include <stdio.h>

int main(void) {
    // Example 1: Copy a string with sufficient buffer size
    char dest1[20];
    char src1[] = "Hello, World!";
    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));
    printf("Example 1:\n");
    printf("Destination: %s\n", dest1);
    printf("Number of characters copied: %zu\n", result1);
    printf("Buffer size: %zu\n\n", sizeof(dest1));

    // Example 2: Copy a string with insufficient buffer size
    char dest2[10];
    char src2[] = "Hello, World!";
    size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));
    printf("Example 2:\n");
    printf("Destination: %s\n", dest2);
    printf("Number of characters copied: %zu\n", result2);
    printf("Buffer size: %zu\n\n", sizeof(dest2));

    // Example 3: Copy an empty string
    char dest3[10];
    char src3[] = "";
    size_t result3 = ft_strlcpy(dest3, src3, sizeof(dest3));
    printf("Example 3:\n");
    printf("Destination: %s\n", dest3);
    printf("Number of characters copied: %zu\n", result3);
    printf("Buffer size: %zu\n\n", sizeof(dest3));

    return 0;
}
*/
