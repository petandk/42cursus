/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:16:38 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 19:06:39 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	shake(t_game *game)
{
	if (game->shake_frames > 0)
	{
		render_frame(game, 1);
		game->shake_frames--;
	}
	else
		render_frame(game, 0);
}

static void	draw_rays_loop(t_game *game)
{
	int		i;
	float	camera_x;
	float	fov;
	float	fov_factor;

	fov = PI / 3;
	fov_factor = tan(fov / 2);
	i = 0;
	while (i < WIDTH)
	{
		camera_x = 2.0f * i / (float)WIDTH - 1.0f;
		game->ray.ray_angle = game->player.angle + atan(camera_x * fov_factor);
		draw_line(game, i);
		i++;
	}
}

int	draw_loop(t_game *game)
{
	move_player(&game->player, game);
	clear_image(game);
	draw_rays_loop(game);
	if (game->mini_map)
		draw_minimap(game);
	shake(game);
	draw_controls_label(game);
	return (0);
}
