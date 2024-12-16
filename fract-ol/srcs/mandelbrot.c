/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/17 00:24:38 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

t_boundaries	mandelbrot_boundaries(void)
{
	t_boundaries	mandel;

	mandel.x_min = -2;
	mandel.x_max = 1;
	mandel.y_min = -1.5;
	mandel.y_max = 1.5;
	return (mandel);
}

static int	is_mandelbrot(t_complex c)
{
	int			iterations;
	t_complex	z;
	double		temp_real;

	iterations = 0;
	z.real = 0;
	z.imag = 0;
	while (iterations < MAX_ITERATIONS)
	{
		temp_real = (ft_sqare(z.real) - ft_sqare(z.imag)) + c.real;
		z.imag = (2 * z.real * z.imag) + c.imag;
		z.real = temp_real;
		if ((ft_sqare(z.real) + ft_sqare(z.imag)) > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

static void	mandelbrot_help(t_window *window, int x, int y, t_boundaries b, int *palette)
{
	t_complex	point;
	int			iter;

	point.real = b.x_min + (b.x_max - b.x_min) * (double)x / WIDTH;
	point.imag = b.y_min + (b.y_max - b.y_min) * (double)y / HEIGHT;
	iter = is_mandelbrot(point);
	if (iter == MAX_ITERATIONS)
		paint_pixel(window, x, y, 0x000000);
	else
		paint_pixel(window, x, y, palette[iter]);
}

void	generate_mandelbrot(t_window *window)
{
	int				x;
	int				y;
	t_boundaries	b;
	int				*palette;

	b = window->bounds;
	palette = precompute_colors();
	y = 0;
	while (y < HEIGHT)
	{
			x = 0;
		while (x < WIDTH)
		{
			mandelbrot_help(window, x, y, b, palette);
			x++;
		}
		y++;
	}
	free(palette);
}
