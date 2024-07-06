/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:13:19 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/05 13:07:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(unsigned int n, int fd)
{
	int	count;
	int	result;

	count = 0;
	if (n >= 10)
	{
		result = ft_putnbr_recursive(n / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(n % 10 + '0', fd);
	if (result == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbr_fd(int n, int fd)
{
	int	count;
	int	result;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr_fd("-2147483648", fd));
	if (n < 0)
	{
		result = ft_putchar_fd('-', fd);
		if (result == -1)
			return (-1);
		count = 1;
		n = -n;
	}
	result = ft_putnbr_recursive((unsigned int)n, fd);
	if (result == -1)
		return (-1);
	return (count + result);
}

int	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	int	count;
	int	result;

	count = 0;
	if (n > 9)
	{
		result = ft_putunsignednbr_fd(n / 10, fd);
		if (result == -1)
			return (-1);
		count += result;
		result = ft_putunsignednbr_fd(n % 10, fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	else
	{
		result = ft_putchar_fd(n + '0', fd);
		if (result == -1)
			return (-1);
		count++;
	}
	return (count);
}

/*
int	ft_putfloat_fd(float num, int fd)
{
	int	count;
	int	integer;
	int	result;

	integer = (int) num;
	result = ft_putnbr_fd(integer, fd);
	if (result == -1)
		return (-1);
	count = result;
	result = ft_putchar_fd('.', fd);
	if (result == -1)
		return (-1);
	count++;
	num -= integer;
	while (num != 0)
	{
		num *= 10;
		result = ft_putnbr_fd((int)num, fd);
		if (result == -1)
			return (-1);
		count += result;
		num -= (int)num;
	}
	return (count);
}
*/
