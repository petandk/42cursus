/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:40:33 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/14 23:04:30 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	click_x(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}
