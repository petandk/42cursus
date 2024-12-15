/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:38:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 19:52:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	paint_pixel(t_window *win, int x, int y, int color)
{
	char	*dst;

	dst = win->image + (y * win->line_length + x * (win->bits_per_px / 8));
	*(unsigned int *)dst = color;
}
