/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:40:43 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:54:57 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

static int	check_neighbors(int row, int col, t_map *map)
{
	if (row == 0 || col >= ft_strlen(map->map[row - 1]) || !ft_strchr("01",
			map->map[row - 1][col]))
		return (1);
	if (row >= map->maprows - 1 || !map->map[row + 1]
		|| col >= ft_strlen(map->map[row + 1])
		|| !ft_strchr("01", map->map[row + 1][col]))
		return (1);
	if (col == 0 || !ft_strchr("01", map->map[row][col - 1]))
		return (1);
	if (col >= ft_strlen(map->map[row]) - 1 || !ft_strchr("01",
			map->map[row][col + 1]))
		return (1);
	return (0);
}

int	validate_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->map[map->spawnpoint.y][map->spawnpoint.x] = '0';
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0')
			{
				if (check_neighbors(i, j, map))
					return (show_error("no_map"), 0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
