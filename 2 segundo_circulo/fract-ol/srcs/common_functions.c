/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 12:05:04 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 13:13:00 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculate_point(t_complex *point, t_complex xy, t_boundaries b)
{
	point->real = b.x_min + (b.x_max - b.x_min) * (double)xy.real / WIDTH;
	point->imag = b.y_min + (b.y_max - b.y_min) * (double)xy.imag / HEIGHT;
}

void	handle_pixel(t_window *win, t_px_data data, int iter, int *pal)
{
	double	radius;
	double	real_sq;
	double	imag_sq;

	real_sq = (data.point.real * data.point.real);
	imag_sq = (data.point.imag * data.point.imag);
	radius = sqrt(real_sq + imag_sq);
	if (radius <= 2.5)
	{
		if (iter == MAX_ITERATIONS)
			paint_pixel(win, (int)data.xy.real, (int)data.xy.imag, 0x000000);
		else
			paint_pixel(win, (int)data.xy.real, (int)data.xy.imag, pal[iter]);
	}
}

int	check_fractal_type(t_window *win, const char *type)
{
	int	len;

	len = ft_strlen(type);
	return (ft_strncmp(type, win->fractal_type, len) == 0);
}
