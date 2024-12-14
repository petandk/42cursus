/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:44:56 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/14 23:51:56 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>

# define KEY_ESC			65307
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define DESTROY_WINDOW		17

# define WIDTH				800
# define HEIGHT				600

# define MANDELBROT			1
# define JULIA				2

typedef struct s_window
{
	void	*mlx;
	void	*win;
	void	*frame;
	char	*image;
	int		bits_per_px;
	int		line_length;
	int		endian;
}	t_window;

int	key_handler(int key, t_window *window);
int	click_x(t_window *window);
void	paint_pixel(t_window *window, int x, int y, int color);
void	paint_line(t_window *win, int x0,int y0, int x1, int y1, int color);
#endif
