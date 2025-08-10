/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:30 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:53:39 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

int	get_longest_line(char **map)
{
	int	i;
	int	longest;

	i = -1;
	longest = 0;
	while (map && map[++i])
	{
		if (ft_strlen(map[i]) > longest)
			longest = ft_strlen(map[i]);
	}
	return (longest);
}

void	draw_minimap_player(t_game *game, float start_x, float start_y)
{
	t_mini_player	mp;

	mp.rel_x = (game->player.x / BLOCK) - start_x;
	mp.rel_y = (game->player.y / BLOCK) - start_y;
	mp.px = MINIMAP_OFFSET_X + (int)(mp.rel_x * MINIMAP_SIZE);
	mp.py = MINIMAP_OFFSET_Y + (int)(mp.rel_y * MINIMAP_SIZE);
	mp.pi = -2;
	while (mp.pi <= 2)
	{
		mp.pj = -2;
		while (mp.pj <= 2)
		{
			put_pixel(mp.px + mp.pi, mp.py + mp.pj, 0xFF0000, game);
			mp.pj++;
		}
		mp.pi++;
	}
}
