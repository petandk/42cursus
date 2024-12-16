/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/16 22:29:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	print_menu(void)
{
	write(2, "Please run ./fractol followed by:\n", 34);
	write(2, "\"mandelbrot\" to view the mandelbrot fractal\n", 44);
}

static int	init_window(t_window *win)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		return (0);
	win->win = mlx_new_window(win->mlx, WIDTH, HEIGHT, "fract-ol");
	if (!win->win)
		return (0);
	win->frame = mlx_new_image(win->mlx, WIDTH, HEIGHT);
	win->image = mlx_get_data_addr(win->frame,
			&win->bits_per_px,
			&win->line_length,
			&win->endian);
	return (1);
}

static void	mlx_hooks(t_window *win)
{
	mlx_key_hook(win->win, key_handler, win);
	mlx_mouse_hook(win->win, mouse_handler, win);
	mlx_hook(win->win, DESTROY_WINDOW, 0, click_x, win);
}

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc == 1 || (argc > 1 && argv[1][0] == '\0'))
		return (print_menu(), 1);
	if (!init_window(&win))
		return (1);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		win.bounds = mandelbrot_boundaries();
		generate_mandelbrot(&win);
	}
	draw_to_window(&win);
	mlx_hooks(&win);
	mlx_loop(win.mlx);
	return (0);
}
