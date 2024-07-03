/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:13:19 by rmanzana          #+#    #+#             */
/*   Updated: 2024/07/03 19:26:34 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		count = 2 + ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		count = 1 + ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		count += 1;
	}
	return (count);
}

int	ft_putunsignednbr_fd(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunsignednbr_fd(n / 10, fd);
		count += ft_putunsignednbr_fd(n % 10, fd); 
	}
	else
	{
		ft_putchar_fd(n + '0', fd);
		count++;
	}
	return (count);
}

int	ft_putfloat_fd(float num, int fd)
{
	int	count;
	int	integer;
	
	integer = (int) num;
	count = ft_putnbr_fd(integer, fd);
	ft_putchar_fd('.', fd);
	count++;
	num -= integer;
	while (num != 0)
	{
		num *= 10;
		count += ft_putnbr_fd((int)num, fd);
		num -= (int)num;
	}
	return (count);
}

int	ft_puthex_fd(unsigned long long num, int fd, int uppercase)
{
	char			*hexdigits;
	int				count;

	count = 0;
	if (uppercase)
		hexdigits = "0123456789ABCDEF";
	else
		hexdigits = "0123456789abcdef";
	if (num == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	if (num >= 16)
		count += ft_puthex_fd(num / 16, fd, uppercase);
	ft_putchar_fd(hexdigits[num % 16], fd);
	return (count + 1);
}

int	ft_putpointer_fd(void *ptr, int fd)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	addr = (unsigned long long) ptr;
	if (addr != 0)
	{
		count += ft_putstr_fd("0x", fd);
		count += ft_puthex_fd(addr, fd, 0);
	}
	else
		count += ft_putstr_fd("(null)", fd);
	return (count);
}
