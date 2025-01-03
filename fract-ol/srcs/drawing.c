/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:38:58 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 13:22:32 by rmanzana         ###   ########.fr       */
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

int	*precompute_colors(t_window *win)
{
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				*palette;

	palette = malloc((MAX_ITERATIONS + 1) * sizeof(int));
	if (palette == NULL)
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
		palette[i] = (r << 16) | (g << 8) | b;
		i++;
	}
	return (palette);
}

void	clear_canvas(t_window *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			paint_pixel(win, x, y, 0x000000);
			x++;
		}
		y++;
	}
}
