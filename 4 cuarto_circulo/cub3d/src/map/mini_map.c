/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:14 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 16:50:16 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	draw_minimap_cell(t_game *game, int px, int py, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE)
	{
		j = 0;
		while (j < MINIMAP_SIZE)
		{
			put_pixel(px + i, py + j, color, game);
			j++;
		}
		i++;
	}
}

static int	get_minimap_cell_color(t_game *game, int map_x, int map_y)
{
	if (map_y >= 0 && map_x >= 0 && game->map->map[map_y]
		&& game->map->map[map_y][map_x])
	{
		if (game->map->map[map_y][map_x] == '1')
			return (0x333333);
		else if (game->map->map[map_y][map_x] == '0')
			return (0xCCCCCC);
		else
			return (-1);
	}
	return (-1);
}

static void	draw_minimap_cells(t_game *game, t_mini_map *mini_map)
{
	mini_map->y = 0;
	while (mini_map->y < MINIMAP_CELLS)
	{
		mini_map->x = 0;
		while (mini_map->x < MINIMAP_CELLS)
		{
			mini_map->map_x = (int)(mini_map->start_x + mini_map->x);
			mini_map->map_y = (int)(mini_map->start_y + mini_map->y);
			mini_map->px = MINIMAP_OFFSET_X + (int)((mini_map->x
						- (mini_map->start_x - (int)mini_map->start_x))
					* MINIMAP_SIZE);
			mini_map->py = MINIMAP_OFFSET_Y + (int)((mini_map->y
						- (mini_map->start_y - (int)mini_map->start_y))
					* MINIMAP_SIZE);
			mini_map->color = get_minimap_cell_color(game, mini_map->map_x,
					mini_map->map_y);
			if (mini_map->color != -1)
				draw_minimap_cell(game, mini_map->px, mini_map->py,
					mini_map->color);
			mini_map->x++;
		}
		mini_map->y++;
	}
}

void	draw_minimap(t_game *game)
{
	int			map_w;
	int			map_h;
	t_mini_map	mini_map;

	map_w = 0;
	map_h = 0;
	while (game->map->map[map_h])
		map_h++;
	map_w = get_longest_line(game->map->map);
	mini_map.start_x = (game->player.x / BLOCK) - MINIMAP_CELLS / 2.0f;
	mini_map.start_y = (game->player.y / BLOCK) - MINIMAP_CELLS / 2.0f;
	if (mini_map.start_x < 0)
		mini_map.start_x = 0;
	if (mini_map.start_y < 0)
		mini_map.start_y = 0;
	if (mini_map.start_x > map_w - MINIMAP_CELLS)
		mini_map.start_x = map_w - MINIMAP_CELLS;
	if (mini_map.start_y > map_h - MINIMAP_CELLS)
		mini_map.start_y = map_h - MINIMAP_CELLS;
	draw_minimap_cells(game, &mini_map);
	draw_minimap_player(game, mini_map.start_x, mini_map.start_y);
}
