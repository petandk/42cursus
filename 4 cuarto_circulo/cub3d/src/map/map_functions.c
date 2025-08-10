/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:03:16 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 17:03:19 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->map->map[y][x] == '1')
		return (true);
	return (false);
}

int	is_wall(float px, float py, t_game *game)
{
	int	map_x;
	int	map_y;

	map_x = (int)(px / BLOCK);
	map_y = (int)(py / BLOCK);
	if (map_y < 0 || map_x < 0 || !game->map->map[map_y]
		|| !game->map->map[map_y][map_x])
		return (0);
	return (game->map->map[map_y][map_x] == '1');
}

static void	init_offsets(float offsets[4][2])
{
	offsets[0][0] = PLAYER_RADIUS;
	offsets[0][1] = PLAYER_RADIUS;
	offsets[1][0] = -PLAYER_RADIUS;
	offsets[1][1] = PLAYER_RADIUS;
	offsets[2][0] = PLAYER_RADIUS;
	offsets[2][1] = -PLAYER_RADIUS;
	offsets[3][0] = -PLAYER_RADIUS;
	offsets[3][1] = -PLAYER_RADIUS;
}
/*map_x = map[0]
map_y = map[1]*/

int	is_wall_with_radius(float px, float py, t_game *game)
{
	float	offsets[4][2];
	int		i;
	float	check_x;
	float	check_y;
	int		map[2];

	init_offsets(offsets);
	i = 0;
	while (i < 4)
	{
		check_x = px + offsets[i][0];
		check_y = py + offsets[i][1];
		map[0] = (int)(check_x / BLOCK);
		map[1] = (int)(check_y / BLOCK);
		if (map[1] < 0 || map[0] < 0 || !game->map->map[map[1]]
			|| !game->map->map[map[1]][map[0]])
			return (1);
		if (game->map->map[map[1]][map[0]] == '1')
			return (1);
		i++;
	}
	return (0);
}
