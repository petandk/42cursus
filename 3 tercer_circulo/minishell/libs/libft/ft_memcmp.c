/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:20:15 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 15:34:31 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			c;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = ((unsigned char *)s1);
	str2 = ((unsigned char *)s2);
	c = 0;
	while (c < n)
	{
		if (str1[c] != str2[c])
			return ((int)(str1[c] - str2[c]));
		c++;
	}
	return (0);
}
/*
int main (void)
{
	char test_str[20];
	char test_str1[20];
	size_t n;

    printf("Ingresa una cadena: ");
    fgets(test_str, sizeof(test_str), stdin);

	printf("Ingresa una cadena: ");
    fgets(test_str1, sizeof(test_str1), stdin);

	printf("Ingreas un caracter tipo size_t inferior a 20 :");
	if (scanf("%zu",&n) != 1)
	{
		printf("Error al leer el valor.\n");
		return (0);
	}
	if (n > 20)
	{
		printf("El valor de size debe ser inferior a 20.\n");
		return (1);
	}
	int	result = ft_memcmp(test_str, test_str1, n);
    if (result < 0)
 	{
		printf("str1 es menor que str2\n");
    } 
	else if (result > 0) 
	{
        printf("str1 es mayor que str2\n");
    } 
	else {
        printf("str1 es igual a str2 hasta los primeros %zu caracteres\n",n);
    }
    return 0;
}*/
