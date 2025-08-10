/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:54 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 18:58:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

void	draw_map(t_game *game)
{
	char	**map;
	int		color;
	int		x;
	int		y;
	t_point	xy;

	color = 0x0000FF;
	map = game->map->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				xy.x = x * BLOCK;
				xy.y = y * BLOCK;
				draw_square(xy, BLOCK, color, game);
			}
			xy.x++;
		}
		y++;
	}
}

void	draw_square(t_point xy, int size, int color, t_game *game)
{
	int	i;

	i = 0;
	while (i < size)
	{
		put_pixel(xy.x + i, xy.y, color, game);
		put_pixel(xy.x, xy.y + i, color, game);
		put_pixel(xy.x + size, xy.y + i, color, game);
		put_pixel(xy.x + i, xy.y + size, color, game);
		i++;
	}
}

void	draw_sky(t_game *game, int column)
{
	int	y_sky;
	int	sky_color;

	sky_color = game->map->c_color;
	y_sky = 0;
	while (y_sky < game->ray.start_y && y_sky < HEIGHT)
	{
		put_pixel(column, y_sky, sky_color, game);
		y_sky++;
	}
}

void	draw_floor(t_game *game, int column)
{
	int	y_floor;
	int	floor_color;

	floor_color = game->map->f_color;
	y_floor = game->ray.end;
	while (y_floor < HEIGHT)
	{
		put_pixel(column, y_floor, floor_color, game);
		y_floor++;
	}
}

void	draw_wall_column(t_game *game, t_render_column *rc, int column)
{
	int	y;

	y = game->ray.start_y;
	if (y < 0)
		y = 0;
	while (y < game->ray.end)
	{
		set_tex_h(game, rc);
		rc->tex_y = ((y - game->ray.start_y) * rc->tex_h) / game->ray.height;
		if (rc->tex_y < 0)
			rc->tex_y = 0;
		clamp_tex_y(game, rc);
		rc->pixel_color = get_texture_color(game, rc->direction, rc->tex_x,
				rc->tex_y);
		put_pixel(column, y, rc->pixel_color, game);
		y++;
	}
}
