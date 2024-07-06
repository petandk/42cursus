/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:03:40 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/06 11:50:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main(void) 
{
    char c = 'a';
    char *str = "Hello, World!";
    int i = 42;
    unsigned int u = 4294967295;
	int d = -2147483648;
	int	chars;

    printf("+Original printf\n");
	printf("-Your ft_printf\n");
	printf("+%%c: %c\n", c);
	ft_printf("-%%c: %c\n", c);
    printf("+%%s: %s\n", str);
    ft_printf("-%%s: %s\n", str);
	printf("+%%i: %i\n", i);
	ft_printf("-%%i: %i\n", i);
    printf("+%%d: %d\n", d);
	ft_printf("-%%d: %d\n", d);
    printf("+%%u: %u\n", u);
	ft_printf("-%%u: %u\n", u);
    printf("+%%x: %x\n", i);
	ft_printf("-%%x: %x\n", i);
    printf("+%%X: %X\n", i);
	ft_printf("-%%X: %X\n", i);
    printf("+%%%%: %%\n");
	ft_printf("-%%%%: %%\n");
    printf("+%%p: %p\n", &i);
	ft_printf("-%%p: %p\n", &i);
	printf("+sNULL: %s\n", (char *)NULL);
	ft_printf("-sNULL: %s\n", NULL);
	printf("+pNULL: %p\n", NULL);
	ft_printf("-pNULL: %p\n", NULL);	
	printf("+%%s empty: %s\n", "");
	ft_printf("-%%s empty: %s\n", "");
	chars = printf("+La cadena %c con texto %s que incluye el numero %i tiene un tamaño de:", c, str, i);
	printf("+%d\n", chars);
	chars = ft_printf("-La cadena %c con texto %s que incluye el numero %i tiene un tamaño de:", c, str, i);
	ft_printf("-%d\n", chars);
	ft_printf("\nTests de evaluacion:\n");
	ft_printf("%%c: %c\n", 'b');
	ft_printf("%%s: %s\n", "hola que tal");
	ft_printf("%%p: %p\n", &i);
	ft_printf("%%d: %d\n", 456);
	ft_printf("%%i: %i\n", 042);
	ft_printf("%%u: %u\n", 3999999999);
	ft_printf("%%x: %x\n", 255);
	ft_printf("%%X: %X\n", 255);
	ft_printf("%%%%: %%\n");
	ft_printf("-----------------------------------------\n");
	ft_printf("%%d 0: %d\n", 0);
	ft_printf("%%i 0: %i\n", 0);
	ft_printf("%%u 0: %u\n", 0);
	ft_printf("%%d smallest: %d\n", d);
	ft_printf("%%i smallest: %i\n", d);
	ft_printf("%%u smallest: %u\n", d);
	ft_printf("-%%s empty: %s\n", "");
	ft_printf("%%p NULL: %p\n", NULL);
	ft_printf("%%c: %c, %%s: %s, %%p: %p, %%d: %d, %%i: %i, %%u: %u, %%x: %x, %%X: %X, %%%%: %%\n", 'a', "hola", &i, 15, -42, 63, 127, 127);
	ft_printf("Going crazy: %s%s%s%s%i%i%i", "hola", "QUE", "ase", "uteh!", 3, 4, 5);

	return (0);
}

