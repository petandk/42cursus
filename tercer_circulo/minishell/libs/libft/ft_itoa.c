/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:44:51 by gpolo             #+#    #+#             */
/*   Updated: 2024/06/22 14:21:23 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_leng(int n)
{
	int		leng;

	leng = 0;
	if (n == -2147483648)
	{
		leng += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		leng++;
		n *= -1;
	}
	while (n >= 10)
	{
		leng++;
		n /= 10;
	}
	leng++;
	return (leng);
}

int	copm(char *itoa, int n)
{
	if (n == -2147483648)
	{
		itoa[0] = ('-');
		itoa[1] = ('2');
		n = 147483648;
	}
	if (n < 0)
	{
		itoa[0] = ('-');
		n *= -1;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		c;

	c = (ft_leng(n));
	itoa = (char *)ft_calloc((c + 1), sizeof(char));
	if (!itoa)
		return (0);
	n = copm(itoa, n);
	c--;
	while (n >= 10)
	{
		itoa[c--] = n % 10 + '0';
		n /= 10;
	}
	if (n >= 0)
		itoa[c] = n + '0';
	return (itoa);
}
/*
int main ()
{
	int		n;
	char	*itoa;
	
	printf("Ingresa un inter: ");
	scanf("%d",&n);
	itoa = ft_itoa(n);
    if (itoa)
    {
        printf("Resultado en formato de string: %s\n", itoa);
        free(itoa);
    }
    else
    {
        printf("Error: Memoria no asignada\n");
    }
	return (0);
}*/
