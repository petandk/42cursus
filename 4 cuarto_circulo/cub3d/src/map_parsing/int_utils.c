/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:09 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 18:54:33 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	validates is a string contains only digits
	returns 0 if invalid char is found or error
	1 if all chars are numbers.
*/

int	is_valid_number(char *str)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	if (!str)
		return (0);
	str = skip_spaces(str);
	while (str[i] && str[i] != '\n')
	{
		if (ft_isdigit(str[i]))
			has_digit = 1;
		else if (!is_space(str[i]))
			return (0);
		i++;
	}
	return (has_digit);
}
