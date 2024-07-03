/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:47:55 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/03 22:33:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_cases(char c, int output, va_list vargs)
{
	int	ret;

	ret = 1;
	if (c == '%')
		ft_putchar_fd('%', output);
	else if (c == 'c')
		ft_putchar_fd((char)va_arg(vargs, int), output);
	else if (c == 's')
		ret = ft_putstr_fd(va_arg(vargs, char *), output);
	else if (c == 'd' || c == 'i')
		ret = ft_putnbr_fd(va_arg(vargs, int), output);
	else if (c == 'u')
		ret = ft_putunsignednbr_fd(va_arg(vargs, unsigned int), output);
	else if (c == 'x')
		ret = ft_puthex_fd(va_arg(vargs, unsigned int), output, 0);
	else if (c == 'X')
		ret = ft_puthex_fd(va_arg(vargs,unsigned int), output, 1);
	else if (c == 'p')
		ret = ft_putpointer_fd(va_arg(vargs, void *), output);
	else
		ft_putchar_fd(c, output);
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	int		index;
	int		output;
	va_list	vargs;
	int		extrachars;

	index = 0;
	output = 1;
	extrachars = 0;
	va_start(vargs, str);
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1])
		{
			index++;
			extrachars += ft_cases(str[index], output, vargs);
		}
		else
		{
			ft_putchar_fd(str[index], output);
			extrachars++;	
		}
		index++;
	}
	va_end(vargs);
	return (extrachars);
}

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

	chars = printf("+La cadena %c con texto %s que incluye el numero %i tiene un tamaño de:", c, str, i);
	printf("%d\n", chars);
	chars = ft_printf("-La cadena %c con texto %s que incluye el numero %i tiene un tamaño de:", c, str, i);
	ft_printf("%d\n", chars);
	return (0);
}
