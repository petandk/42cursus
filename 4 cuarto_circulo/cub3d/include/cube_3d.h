/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:18:40 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/03 07:53:58 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_3D_H
# define CUBE_3D_H

# define WIDTH 1200
# define HEIGHT 900
# define BLOCK 128
# define COLISION_ANIME 0
# define CLICK_TO_ROTATE 0

# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363
# define N 110
# define M 109
# define K 107
# define ESC 65307

# define PI 3.14159265359

# define MINIMAP_CELLS 20
# define MINIMAP_SIZE 8
# define MINIMAP_OFFSET_X 20
# define MINIMAP_OFFSET_Y 20

# define PLAYER_RADIUS 10

# include "42_Libft/libft.h"
# include "get_next_line.h"
# include "map_parser.h"
# include "mlx_linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;

}				t_player;

typedef struct s_north
{
	void		*tex_n;
	char		*tex_n_data;
	int			tex_n_bpp;
	int			tex_n_size_line;
	int			tex_n_endian;
	int			tex_n_width;
	int			tex_n_height;

}				t_north;

typedef struct s_south
{
	void		*tex_s;
	char		*tex_s_data;
	int			tex_s_bpp;
	int			tex_s_size_line;
	int			tex_s_endian;
	int			tex_s_width;
	int			tex_s_height;
}				t_south;

typedef struct s_west
{
	void		*tex_w;
	char		*tex_w_data;
	int			tex_w_bpp;
	int			tex_w_size_line;
	int			tex_w_endian;
	int			tex_w_width;
	int			tex_w_height;
}				t_west;

typedef struct s_east
{
	void		*tex_e;
	char		*tex_e_data;
	int			tex_e_bpp;
	int			tex_e_size_line;
	int			tex_e_endian;
	int			tex_e_width;
	int			tex_e_height;
}				t_east;

typedef struct s_ray
{
	float		ray_x;
	float		ray_y;
	float		ray_angle;
	float		cos_angle;
	float		sin_angle;
	float		dist;
	int			height;
	int			start_y;
	int			end;
}				t_ray;

typedef struct s_render_column
{
	float		wall_hit;
	int			tex_x;
	int			tex_y;
	int			tex_h;
	int			pixel_color;
	char		direction;
	int			hit_vertical;
	float		hit_x;
	float		hit_y;
	float		corrected_dist;
}				t_render_column;

typedef struct s_dda_vars
{
	int			map_x;
	int			map_y;
	float		delta_dist_x;
	float		delta_dist_y;
	int			hit;
	int			side;
	float		side_dist_x;
	float		side_dist_y;
	int			step_x;
	int			step_y;
}				t_dda_vars;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	t_map		*map;
	int			shake_frames;
	int			bpp;
	int			size_line;
	int			endian;
	int			tex_width;
	int			tex_height;
	t_ray		ray;
	t_player	player;
	t_north		north;
	t_south		south;
	t_west		west;
	t_east		east;
	int			click_to_rotate;
	int			mini_map;
}				t_game;

typedef struct s_mini_map
{
	int			x;
	int			y;
	int			px;
	int			py;
	int			color;
	int			map_x;
	int			map_y;
	float		start_x;
	float		start_y;
	int			margin;
	int			bg_color;
	int			width;
	int			height;
}				t_mini_map;

typedef struct s_mini_player
{
	int			px;
	int			py;
	int			pi;
	int			pj;
	float		rel_x;
	float		rel_y;
}				t_mini_player;

// MAP_FUNCTIONS
bool			touch(float px, float py, t_game *game);
int				is_wall(float px, float py, t_game *game);
int				is_wall_with_radius(float px, float py, t_game *game);

// MINIMAP
void			draw_minimap(t_game *game);

// MINI_MAP_UTILS
int				get_longest_line(char **map);
void			draw_minimap_player(t_game *game, float start_x, float start_y);

// MATH_FUNCTIONS
float			fixed_dist( t_render_column *rc, t_game *game);
void			calc_ray_hit_and_dist(t_game *game, t_render_column *rc);

// PERFORM_DDA
void			perform_dda(t_ray *ray, t_game *game, t_render_column *rc);

// GAME
void			init_game(t_game *game, char *argv);
void			init_ray(t_ray *ray, t_player *player, float start_x);

// DRAW_LINE
void			draw_line(t_game *game, int column);

// DRAW_ELEMENTS
void			draw_map(t_game *game);
void			draw_square(t_point xy, int size, int color, t_game *game);
void			draw_sky(t_game *game, int column);
void			draw_floor(t_game *game, int column);
void			draw_wall_column(t_game *game, t_render_column *rc, int column);

// DRAW_UTILS
int				check_hit_vertical(t_ray *ray);
char			get_wall_direction(t_ray *ray);
void			set_tex_h(t_game *game, t_render_column *rc);
void			clamp_tex_y(t_game *game, t_render_column *rc);

// INIT_TEXTURES
void			init_textures(t_game *game);

// TEXTURE_PIXEL
int				get_texture_color(t_game *game, char direction, int tex_x,
					int tex_y);

// IMG_FUNCTIONS
void			put_pixel(int x, int y, int color, t_game *game);
void			clear_image(t_game *game);
void			calc_tex_x(t_game *game, t_render_column *rc);

// CARDINAL_MOVES
void			up_move(t_player *player, t_game *game, int speed);
void			down_move(t_player *player, t_game *game, int speed);
void			left_move(t_player *player, int speed, t_game *game);
void			right_move(t_player *player, int speed, t_game *game);

// 	MOVE_FUNCTIONS
void			move_player(t_player *player, t_game *game);
void			render_frame(t_game *game, int shake);
void			draw_controls_label(t_game *game);

// INTERACTIVE_FUNCTIONS
void			init_player(t_player *player, t_point spawnpoint,
					char spawndir);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				close_window(t_game *game);

// INTERACTIVE_MOUSE_FUNCTIONS
int				mouse_move(int x, int y, t_game *game);
int				mouse_press(int button, int x, int y, t_game *game);
int				mouse_release(int button, int x, int y, t_game *game);
void			toggle_mouse_mode(t_game *game);

// LOOP
int				draw_loop(t_game *game);

// ERROR_FUNCTIONS
void			show_error(char *type);
void			error_load_textures(t_game *game);
void			init_game_error(t_game *game);

#endif
