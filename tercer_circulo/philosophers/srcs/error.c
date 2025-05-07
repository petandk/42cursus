/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:30:38 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/07 22:31:52 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *type)
{
	if (ft_notstrncmp(type, "no_num", 6) == 0)
		write(2, "Error: only numbers, please!\n", 29);
	else if (ft_notstrncmp(type, "neg_val", 7) == 0)
		write(2, "Error: Only positive values!\n", 29);
	else if (ft_notstrncmp(type, "invalid_args", 12) == 0)
		write(2, "Error: Invalid arguments!\n", 26);
	else if (ft_notstrncmp(type, "init_fail", 9) == 0)
		write(2, "Error: Initialization failed!\n", 30);
}
