/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:35:44 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/18 12:27:14 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main()
{
	char	test_str[20];
	char	c;
	char	c2;
	size_t	n;

	printf("Ingresa un carracter ");
	if (scanf("%c", &c2) != 1)	
	{
		printf("Error al leer el valor.\n");
        return 1;
	}
	printf("Ingresa un carracter a sustituir ");
	if (scanf("%c", &c) != 1)
	{
		printf("Error al leer el valor.\n");
        return 1;
	}
	printf("Ingresa un valor de tipo size_t inferior a 20: ");
    if (scanf("%zu", &n) != 1)
	{
        printf("Error al leer el valor.\n");
        return 1;
    }
	if (n >= 20)
	{
		printf("El valor deve ser inferor a 20.\n");
		return 1;
	}
	memset(test_str, c2, sizeof(test_str) - 1);
	test_str[sizeof(test_str) - 1] = '\0';
	printf("Array antes de ft_memset: %s\n", test_str);
	ft_memset(test_str, c, n);
	printf("Array después de ft_memset: %s\n", test_str);
}*/
/*
int main()
{
    char array[20];
    
	memset(array, 'A', sizeof(array) - 1);
    array[sizeof(array) - 1] = '\0';

    printf("Array antes de ft_memset: %s\n", array);

    ft_memset(array, 'B', 10);

    printf("Array después de ft_memset: %s\n", array);

    return 0;
}*/
