/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 21:01:19 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 21:04:44 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static double	ft_atof_help(const char *str)
{
	double	decimal;
	double	divisor;

	decimal = 0.0;
	divisor = 10.0;
	while (*str)
	{
		decimal = decimal + (*str - '0') / divisor;
		divisor *= 10.0;
		str++;
	}
	return (decimal);
}

double	ft_atof(const char *str)
{
	double	result;
	double	decimal;
	int		sign;

	result = 0.0;
	decimal = 0.0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && *str != '.')
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		decimal = ft_atof_help(str + 1);
	}
	return ((result + decimal) * sign);
}
