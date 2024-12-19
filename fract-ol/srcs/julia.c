/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/19 17:09:55 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_boundaries	julia_boundaries(void)
{
	t_boundaries	julia;

	julia.x_min = -2;
	julia.x_max = 1;
	julia.y_min = -1.5;
	julia.y_max = 1.5;
	return (julia);
}

static int	is_julia(t_complex c)
{
	int			iterations;
	t_complex	z;
	double		temp_real;
	t_complex	old;
	double		p;

	iterations = 0;
	z.real = 0;
	z.imag = 0;
	p = sqrt((c.real - 0.25) * (c.real - 0.25) + c.imag * c.imag);
	if (c.real < p - 2 * (p * p) + 0.25)
		return (MAX_ITERATIONS);
	if ((c.real + 1) * (c.real + 1) + (c.imag * c.imag) < 0.0625)
		return (MAX_ITERATIONS);
	while (iterations < MAX_ITERATIONS)
	{
		if(iterations > 0 && z.real == old.real && z.imag == old.imag)
			return (MAX_ITERATIONS);
		old = z;
		temp_real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp_real;
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

static void	julia_help(t_window *window, int x, int y, t_boundaries b, int *palette)
{
	t_complex	point;
	int			iter;
	double		radius;

	point.real = b.x_min + (b.x_max - b.x_min) * (double)x / WIDTH;
	point.imag = b.y_min + (b.y_max - b.y_min) * (double)y / HEIGHT;
	radius = sqrt(pow(point.real, 2) + pow(point.imag, 2));
	if (radius <= 2.5)
	{
		iter = is_mandelbrot(point);
		if (iter == MAX_ITERATIONS)
			paint_pixel(window, x, y, 0x000000);
		else
			paint_pixel(window, x, y, palette[iter]);
	}
}

void	generate_mandelbrot(t_window *window)
{
	int				x;
	int				y;
	int				*palette;
	t_boundaries	b;

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
