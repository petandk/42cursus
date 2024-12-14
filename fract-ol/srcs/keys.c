/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/14 23:27:04 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_window *window)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit (0);
	}
	return (0);
}
