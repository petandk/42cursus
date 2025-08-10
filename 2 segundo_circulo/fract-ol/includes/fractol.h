/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:44:56 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/04 17:29:16 by rmanzana         ###   ########.fr       */
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
# define KEY_LEFT			97
# define KEY_RIGHT			100
# define KEY_DOWN			115
# define KEY_UP				119
*/
# define KEY_LEFT			65361
# define KEY_RIGHT			65363
# define KEY_DOWN			65364
# define KEY_UP				65362

# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define DESTROY_WINDOW		17

# define WIDTH				800
# define HEIGHT				800

# define JULIA_MAX_REAL			2.0
# define JULIA_MAX_IMAG			2.0

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

typedef struct s_px_data
{
	t_complex	xy;
	t_complex	point;
}	t_px_data;

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
	int				*palette;
}	t_window;

int				julia_pars(const char *r_str, const char *i_str, t_complex *c);
int				check_args(int argc, char *argv[], t_complex *julia_const);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *s);
double			ft_atof(const char *str);
int				key_handler(int key, t_window *window);
int				mouse_handler(int button, int x, int y, t_window *win);
int				click_x(t_window *window);
void			paint_pixel(t_window *window, int x, int y, int color);
void			precompute_colors(t_window *win);
void			clear_canvas(t_window *win);
t_boundaries	mandelbrot_boundaries(void);
void			generate_mandelbrot(t_window *window);
void			draw_to_window(t_window *win);
t_boundaries	julia_boundaries(void);
void			generate_julia(t_window *window);
void			destroy_window(t_window *win);
int				is_float(const char *str);
void			calculate_point(t_complex *point, t_complex xy, t_boundaries b);
void			handle_pixel(t_window *win, t_px_data data, int iter, int *pal);
int				check_fractal_type(t_window *win, const char *type);
int				julia_pars(const char *r_str, const char *i_str, t_complex *c);

#endif
