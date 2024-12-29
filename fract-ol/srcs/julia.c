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

	julia.x_min = -2.0;
	julia.x_max = 2.0;
	julia.y_min = -2.0;
	julia.y_max = 2.0;
	return (julia);
}

static int	is_julia(t_complex z, t_complex c)
{
	int			iterations;
	double		temp_real;
	t_complex	old;
	double		z_abs;

	iterations = 0;
	while (iterations < MAX_ITERATIONS)
	{
		if ((iterations > 0 && iterations % 10 == 0)
			&& (z.real == old.real && z.imag == old.imag))
			return (MAX_ITERATIONS);
		old = z;
		temp_real = (z.real * z.real) - (z.imag * z.imag) + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = temp_real;
		z_abs = (z.real * z.real) + (z.imag * z.imag);
		if (z_abs > 4)
			return (iterations);
		iterations++;
	}
	return (iterations);
}

static void	julia_help(t_window *window, t_complex xy, t_boundaries b, int *pal)
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
		iter = is_julia(point, window->julia_constant);
		if (iter == MAX_ITERATIONS)
			paint_pixel(window, x, y, 0x000000);
		else
			paint_pixel(window, x, y, pal[iter]);
	}
}

void	generate_julia(t_window *window)
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
			xy = (t_complex){x, y};
			julia_help(window, xy, b, palette);
			x++;
		}
		y++;
	}
	free(palette);
}
