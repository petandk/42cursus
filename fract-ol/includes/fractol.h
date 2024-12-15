/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:44:56 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 21:22:26 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# define KEY_ESC			65307
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define DESTROY_WINDOW		17

# define WIDTH				800
# define HEIGHT				600
# define IN_COLOR			0x005500
# define OUT_COLOR			0xADD8E6

# define MANDELBROT			1
# define JULIA				2

# define MAX_ITERATIONS		1000

typedef struct s_boundaries
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_boundaries;

typedef struct s_window
{
	void			*mlx;
	void			*win;
	void			*frame;
	char			*image;
	int				bits_per_px;
	int				line_length;
	int				endian;
	t_boundaries	bounds;
}	t_window;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				key_handler(int key, t_window *window);
int				click_x(t_window *window);
double			ft_sqare(double num);
void			paint_pixel(t_window *window, int x, int y, int color);
t_boundaries	mandelbrot_boundaries(void);
void			generate_mandelbrot(t_window *window);

#endif
