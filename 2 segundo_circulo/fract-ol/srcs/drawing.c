/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:38:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 23:13:23 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = win->image + (y * win->line_length + x * (win->bits_per_px / 8));
	*(unsigned int *)dst = color;
}

void	draw_to_window(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->frame, 0, 0);
}

void	precompute_colors(t_window *win)
{
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	win->palette = malloc((MAX_ITERATIONS + 1) * sizeof(int));
	if (win->palette == NULL)
	{
		write(2, "Failed to allocate memory for color palette\n", 44);
		destroy_window(win);
		exit(1);
	}
	i = 0;
	while (i <= MAX_ITERATIONS)
	{
		r = (i * 2) % 255;
		g = (i * 15) % 255;
		b = (i * 6) % 255;
		win->palette[i] = (r << 16) | (g << 8) | b;
		i++;
	}
}

void	clear_canvas(t_window *win)
{
	unsigned char	*ptr;
	int				total_size;
	int				i;

	ptr = (unsigned char *)win->image;
	total_size = win->line_length * HEIGHT;
	i = 0;
	while (i < total_size)
		ptr[i++] = 0;
}
