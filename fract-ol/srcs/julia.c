/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 18:30:35 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 13:16:14 by rmanzana         ###   ########.fr       */
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

int	julia_pars(const char *r_str, const char *i_str, t_complex *c)
{
	if (!is_float(r_str) || !is_float(i_str))
		return (write(2, "Julia parameters should be valid numbers\n", 41), 0);
	c->real = ft_atof(r_str);
	c->imag = ft_atof(i_str);
	if (c->real > JULIA_MAX_REAL || c->real < -JULIA_MAX_REAL
		|| c->imag > JULIA_MAX_IMAG || c->imag < -JULIA_MAX_IMAG)
	{
		write(2, "Julia parameters should be between -2 and 2\n", 44);
		return (0);
	}
	return (1);
}

static void	julia_help(t_window *window, t_complex xy, t_boundaries b, int *pal)
{
	t_px_data	data;
	int			iter;

	data.xy = xy;
	calculate_point(&data.point, xy, b);
	iter = is_julia(data.point, window->julia_constant);
	handle_pixel(window, data, iter, pal);
}

void	generate_julia(t_window *window)
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
			xy = (t_complex){x, y};
			julia_help(window, xy, b, palette);
			x++;
		}
		y++;
	}
	free(palette);
}
