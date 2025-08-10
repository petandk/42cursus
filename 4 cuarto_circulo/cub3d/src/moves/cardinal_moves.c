/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cardinal_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:36:26 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:54:03 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

void	up_move(t_player *player, t_game *game, int speed)
{
	float	next_x;
	float	next_y;

	if (player->key_up)
	{
		next_x = player->x + cos(player->angle) * speed;
		next_y = player->y + sin(player->angle) * speed;
		if (!is_wall_with_radius(next_x, next_y, game))
		{
			player->x = next_x;
			player->y = next_y;
		}
		else if (!COLISION_ANIME)
			game->shake_frames = 5;
	}
}

void	down_move(t_player *player, t_game *game, int speed)
{
	float	next_x;
	float	next_y;

	if (player->key_down)
	{
		next_x = player->x - cos(player->angle) * speed;
		next_y = player->y - sin(player->angle) * speed;
		if (!is_wall_with_radius(next_x, next_y, game))
		{
			player->x = next_x;
			player->y = next_y;
		}
		else if (!COLISION_ANIME)
			game->shake_frames = 5;
	}
}

void	left_move(t_player *player, int speed, t_game *game)
{
	float	next_x;
	float	next_y;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_left)
	{
		next_x = player->x + sin_angle * speed;
		next_y = player->y - cos_angle * speed;
		if (!is_wall_with_radius(next_x, next_y, game))
		{
			player->x = next_x;
			player->y = next_y;
		}
		else if (!COLISION_ANIME)
			game->shake_frames = 5;
	}
}

void	right_move(t_player *player, int speed, t_game *game)
{
	float	next_x;
	float	next_y;
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_right)
	{
		next_x = player->x - sin_angle * speed;
		next_y = player->y + cos_angle * speed;
		if (!is_wall_with_radius(next_x, next_y, game))
		{
			player->x = next_x;
			player->y = next_y;
		}
		else if (!COLISION_ANIME)
			game->shake_frames = 5;
	}
}
