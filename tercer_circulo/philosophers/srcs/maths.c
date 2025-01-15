/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/15 20:49:15 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			max_int;

	sign = 1;
	result = 0;
	max_int = 2147483647;
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
		sign = -1;
	else if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if (result > max_int && sign == 1)
			return (max_int);
		if (result > max_int && sign == -1)
			return (-max_int - 1);
		str++;
	}
	return (sign * result);
}
