/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:42:20 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 11:59:37 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_float(const char *str)
{
	int	i;
	int	digit;
	int	dec_count;

	i = 0;
	digit = 0;
	dec_count = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			dec_count++;
			if (dec_count > 1)
				return (0);
		}
		else if (!is_digit(str[i]))
			return (0);
		else
			digit = 1;
		i++;
	}
	return (digit);
}

static double	ft_atof_help(const char *str, int *sign)
{
	double	result;
	double	decimal;
	double	divisor;

	result = 0.0;
	decimal = 0.0;
	divisor = 10.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign = -1;
		str++;
	}
	while (*str && *str != '.')
		result = result * 10.0 + (*str++ - '0');
	if (*str++ != '.')
		return (result);
	while (*str)
	{
		decimal += (*str++ - '0') / divisor;
		divisor *= 10.0;
	}
	return (result + decimal);
}

double	ft_atof(const char *str)
{
	int		sign;

	sign = 1;
	if (!is_float(str))
		return (0.0);
	return (ft_atof_help(str, &sign) * sign);
}
