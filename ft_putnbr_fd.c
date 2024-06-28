/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:09:39 by rmanzana          #+#    #+#             */
/*   Updated: 2024/06/28 19:28:25 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
/*
int	main(void)
{
	int	number = -2147483648;
	ft_putnbr_fd(number, 1);
	ft_putchar_fd("\n" , 1);
	number = 45;
	ft_putnbr_fd(number, 1);
	ft_putchar_fd("\n", 1);
	number = -67;
	ft_putnbr_fd(number, 1);
	ft_putchar_fd("\n", 1);
	number = 2147483647;
	ft_putnbr_fd(number, 1);
	return (0);
}
*/
