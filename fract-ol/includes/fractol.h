/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:44:56 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/19 15:58:52 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>

# define KEY_ESC			65307
# define KEY_R				114
/*
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_DOWN			125
# define KEY_UP				126
*/
# define KEY_LEFT			97
# define KEY_RIGHT			100
# define KEY_DOWN			115
# define KEY_UP				119

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define DESTROY_WINDOW		17

# define WIDTH				800
# define HEIGHT				800

# define MANDELBROT			1
# define JULIA				2

# define MAX_ITERATIONS		100

typedef struct s_boundaries
{
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
}	t_boundaries;

typedef struct s_complex
{
	double	real;
	double	imag;
}	t_complex;

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
	char			*fractal_type;
	t_complex		julia_constant;
}	t_window;

int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
double			ft_atof(const char *str);
int				key_handler(int key, t_window *window);
int				mouse_handler(int button, int x, int y, t_window *win);
int				click_x(t_window *window);
double			ft_sqare(double num);
void			paint_pixel(t_window *window, int x, int y, int color);
int				*precompute_colors(void);
t_boundaries	mandelbrot_boundaries(void);
void			generate_mandelbrot(t_window *window);
void			draw_to_window(t_window *win);
t_boundaries	julia_boundaries(void);
void			generate_julia(t_window *window);

#endif
