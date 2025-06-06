/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/02 14:35:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static const char	*notatoi_help(const char *str, int	*error)
{
	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	if (*str == '-')
	{
		*error = -1;
		print_error("neg_val");
		return (str);
	}
	if (*str == '+')
		str++;
	return (str);
}

static int	convert_digits(const char *str, int *error)
{
	long long	result;
	int			max_int;

	result = 0;
	max_int = 2147483647;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
		{
			result = result * 10 + (*str - '0');
			if (result > max_int)
				return (max_int);
		}
		else
		{
			*error = -1;
			if (*str != '-')
				print_error("no_num");
			return (-1);
		}
		str++;
	}
	return (result);
}

int	ft_notatoi(const char *str, int *error)
{
	if (*error != 0)
		return (-1);
	str = notatoi_help(str, error);
	if (*error != 0)
		return (-1);
	return (convert_digits(str, error));
}

long long	ft_gettime_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((long long)tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
