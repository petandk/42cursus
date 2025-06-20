/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpolo <gpolo@student.42barcelona.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:22:10 by gpolo             #+#    #+#             */
/*   Updated: 2024/10/04 13:34:16 by gpolo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	c;
	int	num;
	int	sig;

	sig = 1;
	c = 0;
	num = 0;
	while ((str[c] == 32) || ((str[c] >= 9) && (str[c] <= 13)))
		c++;
	if ((str[c] == 45) || (str[c] == 43))
	{
		if (str[c] == 45)
			sig *= -1;
		c++;
	}
	while (str[c] >= 48 && str[c] <= 57)
	{
		num = num * 10 + (str[c] - 48);
		c++;
	}
	return (num * sig);
}
/*
int main(void)
{
    const char *str1 = "12345";
    const char *str2 = "-6789";
    const char *str3 = "42abc";
    const char *str4 = "abc42";
    const char *str5 = "    314";
    
    int num1 = atoi(str1);
    int num2 = atoi(str2);
    int num3 = atoi(str3);
    int num4 = atoi(str4);
    int num5 = atoi(str5);

    printf("atoi str1: %s -> %d\n", str1, num1);
    printf("atoi str2: %s -> %d\n", str2, num2);
    printf("atoi str3: %s -> %d\n", str3, num3);
    printf("atoi str4: %s -> %d\n", str4, num4);
    printf("atoi str5: %s -> %d\n", str5, num5);

	num1 = ft_atoi(str1);
    num2 = ft_atoi(str2);
    num3 = ft_atoi(str3);
    num4 = ft_atoi(str4);
    num5 = ft_atoi(str5);

    printf("ft_atoi str1: %s -> %d\n", str1, num1);
    printf("ft_atoi str2: %s -> %d\n", str2, num2);
    printf("ft_atoi str3: %s -> %d\n", str3, num3);
    printf("ft_atoi str4: %s -> %d\n", str4, num4);
    printf("ft_atoi str5: %s -> %d\n", str5, num5);
    
	return 0;
}*/
