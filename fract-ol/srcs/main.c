/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 21:24:01 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_window	win;

	if (argc == 1 || (argc > 1 && argv[1][0] == '\0'))
		return (write(2, "Please run ./fractol mandelbrot to check the mandelbrot fractal\n", 64), 1);
	win.mlx = mlx_init();
	if (!win.mlx)
		return (1);
	win.win = mlx_new_window(win.mlx, WIDTH, HEIGHT, "fract-ol");
	if (!win.win)
		return (1);
	win.frame = mlx_new_image(win.mlx, WIDTH, HEIGHT);
	win.image = mlx_get_data_addr(win.frame,
			&win.bits_per_px,
			&win.line_length,
			&win.endian);
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
	{
		win.bounds = mandelbrot_boundaries();
		generate_mandelbrot(&win);
	}
	mlx_put_image_to_window(win.mlx, win.win, win.frame, 0, 0);
	mlx_key_hook(win.win, key_handler, &win);
	mlx_hook(win.win, DESTROY_WINDOW, 0, click_x, &win);
	mlx_loop(win.mlx);
	return (0);
}
