/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:00:23 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/04 17:34:08 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	move_view(int key, t_window *win)
{
	double	move_x;
	double	move_y;

	move_x = (win->bounds.x_max - win->bounds.x_min) * 0.05;
	move_y = (win->bounds.y_max - win->bounds.y_min) * 0.05;
	if (key == KEY_LEFT)
	{
		win->bounds.x_min -= move_x;
		win->bounds.x_max -= move_x;
	}
	else if (key == KEY_RIGHT)
	{
		win->bounds.x_min += move_x;
		win->bounds.x_max += move_x;
	}
	else if (key == KEY_DOWN)
	{
		win->bounds.y_min += move_y;
		win->bounds.y_max += move_y;
	}
	else if (key == KEY_UP)
	{
		win->bounds.y_min -= move_y;
		win->bounds.y_max -= move_y;
	}
}

int	key_handler(int key, t_window *win)
{
	if (key == KEY_ESC)
	{
		destroy_window(win);
		exit (0);
	}
	if (key == KEY_R || (key >= KEY_LEFT && key <= KEY_DOWN))
	{
		if (key == KEY_R)
		{
			clear_canvas(win);
			if (check_fractal_type(win, "mandelbrot"))
				win->bounds = mandelbrot_boundaries();
			else if (check_fractal_type(win, "julia"))
				win->bounds = julia_boundaries();
		}
		else if (key >= KEY_LEFT && key <= KEY_DOWN)
			move_view(key, win);
		if (check_fractal_type(win, "mandelbrot"))
			generate_mandelbrot(win);
		else if (check_fractal_type(win, "julia"))
			generate_julia(win);
		draw_to_window(win);
	}
	return (0);
}

int	click_x(t_window *window)
{
	destroy_window(window);
	exit(0);
	return (0);
}

static t_complex	get_mouse_position(int x, int y, t_window *win)
{
	t_complex	mouse;
	double		aux_x;
	double		aux_y;

	aux_x = (win->bounds.x_max - win->bounds.x_min);
	aux_y = (win->bounds.y_max - win->bounds.y_min);
	mouse.real = win->bounds.x_min + ((double)x / WIDTH) * aux_x;
	mouse.imag = win->bounds.y_min + ((double)y / HEIGHT) * aux_y;
	return (mouse);
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
	mouse = get_mouse_position(x, y, win);
	win->bounds.x_min = mouse.real - (mouse.real - win->bounds.x_min) * zoom;
	win->bounds.x_max = mouse.real + (win->bounds.x_max - mouse.real) * zoom;
	win->bounds.y_min = mouse.imag - (mouse.imag - win->bounds.y_min) * zoom;
	win->bounds.y_max = mouse.imag + (win->bounds.y_max - mouse.imag) * zoom;
	if (check_fractal_type(win, "mandelbrot"))
		generate_mandelbrot(win);
	else if (check_fractal_type(win, "julia"))
		generate_julia(win);
	draw_to_window(win);
	return (0);
}
