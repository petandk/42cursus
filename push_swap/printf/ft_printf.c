/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 11:47:55 by rmanzana          #+#    #+#             */
/*   Updated: 2024/10/01 19:37:05 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_cases(char c, int output, va_list vargs)
{
	int	ret;

	ret = 1;
	if (c == '%')
		ft_singlechar_fd('%', output);
	else if (c == 'c')
		ft_singlechar_fd((char)va_arg(vargs, int), output);
	else if (c == 's')
		ret = ft_putstring_fd(va_arg(vargs, char *), output);
	else if (c == 'd' || c == 'i')
		ret = ft_putnum_fd(va_arg(vargs, int), output);
	else if (c == 'u')
		ret = ft_putunsignednbr_fd(va_arg(vargs, unsigned int), output);
	else if (c == 'x')
		ret = ft_puthex_fd(va_arg(vargs, unsigned int), output, 0);
	else if (c == 'X')
		ret = ft_puthex_fd(va_arg(vargs, unsigned int), output, 1);
	else if (c == 'p')
		ret = ft_putpointer_fd(va_arg(vargs, void *), output);
	else
		ft_singlechar_fd(c, output);
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	int		index;
	va_list	vargs;
	int		result;
	int		totalchars;

	index = 0;
	totalchars = 0;
	va_start(vargs, str);
	while (str[index])
	{
		if (str[index] == '%' && str[index + 1])
			result = ft_cases(str[++index], 1, vargs);
		else
			result = ft_singlechar_fd(str[index], 1);
		if (result == -1)
		{
			va_end(vargs);
			return (-1);
		}
		totalchars += result;
		index++;
	}
	va_end(vargs);
	return (totalchars);
}
