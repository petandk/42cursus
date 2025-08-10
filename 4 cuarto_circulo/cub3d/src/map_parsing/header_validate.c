/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:50:03 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 18:58:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

/*
	checks and sets cardinal direction textures(NO, SO, WE, EA)
	0 = not found
	1 = success
	2 = duplicate detected
*/
int	check_cardinals(char *line, t_map *map)
{
	int	result;

	result = set_texture_value("NO", &map->no_texture, line);
	if (result != 0)
		return (result);
	result = set_texture_value("SO", &map->so_texture, line);
	if (result != 0)
		return (result);
	result = set_texture_value("WE", &map->we_texture, line);
	if (result != 0)
		return (result);
	result = set_texture_value("EA", &map->ea_texture, line);
	if (result != 0)
		return (result);
	return (0);
}

/*
	checks and sets floor/ceiling colors (F, C)
	0 = not found
	1 = success
	2 = duplicate detected
*/
int	check_colors(char *line, t_map *map)
{
	int	result;

	result = set_color_value("F", &map->f_color, line);
	if (result != 0)
		return (result);
	result = set_color_value("C", &map->c_color, line);
	if (result != 0)
		return (result);
	return (0);
}

/*
	main header validation
	processe header lines for textures and colors, detectin duplicates
	0 = not header line
	1 = valid header
	2 = duplicate/error
*/
int	is_header(char *line, t_map *map)
{
	int	result;

	if (line)
	{
		line = skip_spaces(line);
		if (line[0] == '\0' || line[0] == '\n')
			return (1);
		result = check_cardinals(line, map);
		if (result != 0)
			return (result);
		result = check_colors(line, map);
		if (result != 0)
			return (result);
	}
	return (0);
}
