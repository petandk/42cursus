/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:05:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 17:55:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	calc_wall_hit_and_tex_x(t_game *game, t_render_column *rc)
{
	if (rc->hit_vertical)
		rc->wall_hit = (rc->hit_y - floor(rc->hit_y / BLOCK) * BLOCK) / BLOCK;
	else
		rc->wall_hit = (rc->hit_x - floor(rc->hit_x / BLOCK) * BLOCK) / BLOCK;
	if (rc->wall_hit < 0)
		rc->wall_hit += 1.0f;
	if (rc->hit_vertical)
	{
		if (game->ray.cos_angle > 0)
			rc->direction = 'E';
		else
			rc->direction = 'W';
	}
	else
	{
		if (game->ray.sin_angle > 0)
			rc->direction = 'S';
		else
			rc->direction = 'N';
	}
	calc_tex_x(game, rc);
}

void	draw_line(t_game *game, int column)
{
	t_render_column	rc;

	init_ray(&game->ray, &game->player, game->ray.ray_angle);
	calc_ray_hit_and_dist(game, &rc);
	calc_wall_hit_and_tex_x(game, &rc);
	game->ray.height = (int)((BLOCK / game->ray.dist) * (WIDTH / 2));
	game->ray.start_y = (HEIGHT - game->ray.height) / 2;
	game->ray.end = game->ray.start_y + game->ray.height;
	if (game->ray.end > HEIGHT)
		game->ray.end = HEIGHT;
	draw_wall_column(game, &rc, column);
	draw_sky(game, column);
	draw_floor(game, column);
}
