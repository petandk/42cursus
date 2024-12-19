/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:23 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/19 16:00:09 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_handler(int key, t_window *window)
{
	if (key == KEY_ESC)
	{
		mlx_destroy_window(window->mlx, window->win);
		exit (0);
	}else if(key == KEY_R && ft_strncmp("mandelbrot", window->fractal_type, sizeof(window->fractal_type)) == 0)
	{
		window->bounds = mandelbrot_boundaries();
		generate_mandelbrot(window);
		draw_to_window(window);
	}
	return (0);
}

int	click_x(t_window *window)
{
	mlx_destroy_window(window->mlx, window->win);
	exit(0);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_window *win)
{
	double		zoom;
	t_complex	mouse;

	if (button == MOUSE_SCROLL_UP)
		zoom = 0.9;
	else if (button == MOUSE_SCROLL_DOWN)
		zoom = 1.1;
	else
		return (1);
	mouse.real = win->bounds.x_min + (win->bounds.x_max - win->bounds.x_min) * ((double)x / WIDTH);
	mouse.imag = win->bounds.y_min + (win->bounds.y_max - win->bounds.y_min) * ((double)y / HEIGHT);
	win->bounds.x_min = mouse.real - (mouse.real - win->bounds.x_min) * zoom;
	win->bounds.x_max = mouse.real + (win->bounds.x_max - mouse.real) * zoom;
	win->bounds.y_min = mouse.imag - (mouse.imag - win->bounds.y_min) * zoom;
	win->bounds.y_max = mouse.imag + (win->bounds.y_max - mouse.imag) * zoom;
	generate_mandelbrot(win);
	draw_to_window(win);
	return (0);
}
