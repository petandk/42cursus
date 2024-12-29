/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:35 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/19 12:27:01 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	t_complex	old;
	double		p;

	iterations = 0;
	z = (t_complex){0, 0};
	p = sqrt((c.real - 0.25) * (c.real - 0.25) + c.imag * c.imag);
	if ((c.real < p - 2 * (p * p) + 0.25)
		|| ((c.real + 1) * (c.real + 1) + (c.imag * c.imag) < 0.0625))
		return (MAX_ITERATIONS);
	while (iterations < MAX_ITERATIONS)
	{
		if (iterations > 0 && iterations % 10 == 0
			&& z.real == old.real && z.imag == old.imag)
			return (MAX_ITERATIONS);
		old = z;
		temp_real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z = (t_complex){temp_real, 2 * z.real * z.imag + c.imag};
		if ((z.real * z.real) + (z.imag * z.imag) > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

static void	mandel_help(t_window *win, t_complex xy, t_boundaries b, int *pal)
{
	t_complex	point;
	int			iter;
	double		radius;
	int			x;
	int			y;

	x = xy.real;
	y = xy.imag;
	point.real = b.x_min + (b.x_max - b.x_min) * (double)x / WIDTH;
	point.imag = b.y_min + (b.y_max - b.y_min) * (double)y / HEIGHT;
	radius = sqrt(pow(point.real, 2) + pow(point.imag, 2));
	if (radius <= 2.5)
	{
		iter = is_mandelbrot(point);
		if (iter == MAX_ITERATIONS)
			paint_pixel(win, x, y, 0x000000);
		else
			paint_pixel(win, x, y, pal[iter]);
	}
}

void	generate_mandelbrot(t_window *window)
{
	int				x;
	int				y;
	int				*palette;
	t_boundaries	b;
	t_complex		xy;

	b = window->bounds;
	palette = precompute_colors();
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			xy.real = x;
			xy.imag = y;
			mandel_help(window, xy, b, palette);
			x++;
		}
		y++;
	}
	free(palette);
}
