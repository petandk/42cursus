/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:15:36 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/19 16:54:25 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	while ((s1[c]) && (s2[c]) && (c < n))
	{
		if (s1[c] != s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		c++;
	}
	if (c < n)
		return ((unsigned char)s1[c] - (unsigned char)s2[c]);
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
	int	result = ft_strncmp(test_str, test_str1, n);
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
