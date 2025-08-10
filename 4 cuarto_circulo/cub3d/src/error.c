/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:15:50 by pamanzan          #+#    #+#             */
/*   Updated: 2025/08/03 10:24:55 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	Error messages compilation
	if (ft_strcmp(type, "") == 0)
*/

void	show_error(char *type)
{
	ft_putstr_fd("Error: ", 2);
	if (ft_strcmp(type, "fd") == 0)
		ft_putendl_fd("fd", 2);
	else if (ft_strcmp(type, "spawn") == 0)
		ft_putendl_fd("Found multiple spawn points", 2);
	else if (ft_strcmp(type, "no_spawn") == 0)
		ft_putendl_fd("No spawn point found in map", 2);
	else if (ft_strcmp(type, "bad_header") == 0)
		ft_putendl_fd("Invalid map header", 2);
	else if (ft_strcmp(type, "bad_texture") == 0)
		ft_putendl_fd("Invalid texture extension", 2);
	else if (ft_strcmp(type, "bad_color") == 0)
		ft_putendl_fd("Invalid color", 2);
	else if (ft_strcmp(type, "miss_header") == 0)
		ft_putendl_fd("Missing required header elements", 2);
	else if (ft_strcmp(type, "no_map") == 0)
		ft_putendl_fd("Invalid map/not enclosed", 2);
	else if (ft_strcmp(type, "usage") == 0)
		ft_putendl_fd("Usage-> ./cube_3d maps/mapname.cub", 2);
	else if (ft_strcmp(type, "map_extension") == 0)
		ft_putendl_fd("Wrong map file extension", 2);
	exit(EXIT_FAILURE);
}

void	error_load_textures(t_game *game)
{
	if (!game->north.tex_n)
		ft_putstr_fd("Error loading north texture\n", 2);
	else if (!game->south.tex_s)
		ft_putstr_fd("Error loading south texture\n", 2);
	else if (!game->east.tex_e)
		ft_putstr_fd("Error loading east texture\n", 2);
	else if (!game->west.tex_w)
		ft_putstr_fd("Error loading west texture\n", 2);
	exit(EXIT_FAILURE);
}

void	init_game_error(t_game *game)
{
	if (!game->map)
	{
		show_error("no_map");
		exit(1);
	}
	if (!game->map->map)
	{
		ft_putendl_fd("ERROR: map->map is NULL", 2);
		exit(1);
	}
}
