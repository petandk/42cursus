/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:38:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/17 00:17:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->image + (y * win->line_length + x * (win->bits_per_px / 8));
	*(unsigned int *)dst = color;
}

void	draw_to_window(t_window *win)
{
	mlx_put_image_to_window(win->mlx, win->win, win->frame, 0, 0);
}

int *precompute_colors(void)
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
		exit(1);
	}
	i = 0;
	while (i <= MAX_ITERATIONS)
	{		
		r = 0;
		g = (i * 15) % 255;
		b = (i * 5) % 255;
		palette[i] = (r << 16) | (g << 8) | b;
		i++;
	}
	return (palette);
}

