/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 23:06:28 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_menu(void)
{
	write(2, "Please run ./fractol followed by:\n", 34);
	write(2, "\"mandelbrot\" to view the mandelbrot fractal\n", 44);
	write(2, "\"julia\" followed by some constants ", 35);
	write(2, "to view different julia fractals\n", 33);
	write(2, "Some cool julia constants to try:\n", 35);
	write(2, "-0.4 0.6\n", 9);
	write(2, "0.285 0.01\n", 11);
	write(2, "-0.8 0.156\n", 11);
	write(2, "-0.7269 0.1889\n", 15);
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
	win->palette = NULL;
	precompute_colors(win);
	return (1);
}

static void	mlx_hooks(t_window *win)
{
	mlx_key_hook(win->win, key_handler, win);
	mlx_mouse_hook(win->win, mouse_handler, win);
	mlx_hook(win->win, DESTROY_WINDOW, 0, click_x, win);
}

static void	main_help(t_window *win)
{
	draw_to_window(win);
	mlx_hooks(win);
	mlx_loop(win -> mlx);
}

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc == 1 || (argc > 1 && argv[1][0] == '\0'))
		return (print_menu(), 1);
	if (!init_window(&win))
		return (destroy_window(&win), 1);
	win.fractal_type = argv[1];
	if ((ft_strncmp(argv[1], "mandelbrot", 10) == 0) && argc == 2)
	{
		win.bounds = mandelbrot_boundaries();
		generate_mandelbrot(&win);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0)
	{
		if (argc != 4)
			return (write(2, "\"julia\" set needs 2 more parameters\n", 36), 1);
		if (!julia_pars(argv[2], argv[3], &win.julia_constant))
			return (destroy_window(&win), 1);
		win.bounds = julia_boundaries();
		generate_julia(&win);
	}
	else
		return (write(2, "Invalid fractal type\n", 21), 1);
	main_help(&win);
	return (0);
}
