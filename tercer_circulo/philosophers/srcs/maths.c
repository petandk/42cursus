/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:56:34 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/18 19:17:36 by rmanzana         ###   ########.fr       */
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

int	ft_notatoi(const char *str)
{
	long long	result;
	int			error;
	int			max_int;

	error = 0;
	result = 0;
	max_int = 2147483647;
	str = notatoi_help(str, &error);
	if (error)
		return (-1);
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
