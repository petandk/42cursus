/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/22 19:44:06 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*notatoi_help(const char *str, int	*error)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		*error = 1;
		print_error("neg_val");
		return (str);
	}
	if (*str == '+')
		str++;
	return (str);
}

int	ft_notatoi(const char *str, int *error)
{
	long long	result;
	int			max_int;

	result = 0;
	max_int = 2147483647;
	if (*error != 0)
		return (-1);
	str = notatoi_help(str, error);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			if (result > max_int)
				return (max_int);
		}
		else
			return (print_error("no_num"), -1);
		str++;
	}
	return (result);
}

long long	ft_gettime_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
