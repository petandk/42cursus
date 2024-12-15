/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 21:22:51 by rmanzana         ###   ########.fr       */
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

int	click_x(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}
/*
int	mouse_handler(int button, int x, int y, t_window *window)
{
	t_complex	mouse;
	
	x++;
	y++;
	if (button == MOUSE_SCROLL_UP)
	{
		generate_mandelbrot(window);
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		generate_mandelbrot(window);
	}
	return (0);
}
*/
