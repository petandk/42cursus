/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/04 16:49:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	t_complex	julia_const;

	if (!check_args(argc, argv, &julia_const))
		return (1);
	if (!init_window(&win))
		return (1);
	win.fractal_type = argv[1];
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		win.bounds = mandelbrot_boundaries();
		generate_mandelbrot(&win);
	}
	else
	{
		win.julia_constant = julia_const;
		win.bounds = julia_boundaries();
		generate_julia(&win);
	}
	main_help(&win);
	return (0);
}
