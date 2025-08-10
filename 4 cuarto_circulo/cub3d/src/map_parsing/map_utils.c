/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:41:15 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:58:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	initializes map structure with default values
	pointers = NULL
	numbers = 0
*/
void	map_init(t_map *map)
{
	map->no_texture = NULL;
	map->so_texture = NULL;
	map->ea_texture = NULL;
	map->we_texture = NULL;
	map->c_color = 0;
	map->f_color = 0;
	map->map = NULL;
	map->maprows = 0;
	map->spawnpoint.x = -1;
	map->spawnpoint.y = -1;
	map->spawn_dir = '\0';
}

/*
	frees all allocated memory for map structure
*/
void	free_map(t_map *map)
{
	free(map->no_texture);
	free(map->so_texture);
	free(map->ea_texture);
	free(map->we_texture);
	if (map->map)
		ft_free_array(map->map);
}

/*
	cleanup function for error cases and exit
*/
void	clean_and_exit(int fd, t_map *map)
{
	cleanup_gnl(fd);
	free_map(map);
	free(map);
	close(fd);
}
