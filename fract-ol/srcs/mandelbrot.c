/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 13:15:12 by rmanzana         ###   ########.fr       */
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
	t_px_data	data;
	int			iter;

	data.xy = xy;
	calculate_point(&data.point, xy, b);
	iter = is_mandelbrot(data.point);
	handle_pixel(win, data, iter, pal);
}

void	generate_mandelbrot(t_window *window)
{
	int				x;
	int				y;
	int				*palette;
	t_boundaries	b;
	t_complex		xy;

	b = window->bounds;
	palette = precompute_colors(window);
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
