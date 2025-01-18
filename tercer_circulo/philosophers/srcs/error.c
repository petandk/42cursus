/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:30:38 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/18 19:09:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *type)
{
	if (ft_notstrncmp(type, "no_num", 6) == 0)
		write(2, "Error: only numbers, please!\n", 29);
	if (ft_notstrncmp(type, "neg_val", 7) == 0)
		write(2, "Error: Only positive values!\n", 29);
}
