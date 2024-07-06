/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:35:04 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/04 15:35:56 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_fd(unsigned long long num, int fd, int uppercase)
{
	char	*hexdigits;
	int		count;
	int		result;

	count = 0;
	hexdigits = "0123456789abcdef";
	if (uppercase)
		hexdigits = "0123456789ABCDEF";
	if (num == 0)
	{
		result = ft_putchar_fd('0', fd);
		return (result);
	}
	if (num >= 16)
	{
		result = ft_puthex_fd(num / 16, fd, uppercase);
		if (result == -1)
			return (-1);
		count += result;
	}
	result = ft_putchar_fd(hexdigits[num % 16], fd);
	if (result == -1)
		return (-1);
	count += result;
	return (count + 1);
}

int	ft_putpointer_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;
	int					result;

	count = 0;
	addr = (unsigned long long) ptr;
	if (addr != 0)
	{
		result = ft_putstr_fd("0x", fd);
		if (result == -1)
			return (-1);
		count += result;
		result = ft_puthex_fd(addr, fd, 0);
		if (result == -1)
			return (-1);
		count += result;
	}
	else
	{
		result = ft_putstr_fd("(nil)", fd);
		if (result == -1)
			return (-1);
		count += result;
	}
	return (count);
}
