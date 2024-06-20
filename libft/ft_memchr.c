/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:16:43 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/20 13:10:52 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;
	unsigned char	*spt;

	index = 0;
	spt = (unsigned char *)s;
	while (index < n)
	{
		if (spt[index] == (unsigned char) c)
			return ((void *)spt + index);
		index++;
	}
	return (NULL);
}
/*
int main(void)
{
    // Test 1: Find 'i' in "Lorem ipsum dolor sit amet"
    char str1[] = "Lorem ipsum dolor sit amet";
    char *result1 = ft_memchr(str1, 'i', 17);
    if (result1 == NULL)
        printf("Test 1 failed\n");
    else
        printf("Test 1 passed\n");

    // Test 2: Find 'x' in "Lorem ipsum dolor sit amet"
    char str2[] = "Lorem ipsum dolor sit amet";
    char *result2 = ft_memchr(str2, 'x', 17);
    if (result2 != NULL)
        printf("Test 2 failed\n");
    else
        printf("Test 2 passed\n");

    // Test 3: Find 'm' in "Lorem ipsum dolor sit amet"
    char str3[] = "Lorem ipsum dolor sit amet";
    char *result3 = ft_memchr(str3, 'm', 17);
    if (result3 == NULL)
        printf("Test 3 failed\n");
    else
        printf("Test 3 passed\n");

    // Test 4: Find 'n' in "Lorem ipsum dolor sit amet" with n = 1
    char str4[] = "Lorem ipsum dolor sit amet";
    char *result4 = ft_memchr(str4, 'n', 1);
    if (result4 != NULL)
        printf("Test 4 failed\n");
    else
        printf("Test 4 passed\n");

    return (0);
}
*/
