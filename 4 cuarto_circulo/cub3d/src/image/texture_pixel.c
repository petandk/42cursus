/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:04:18 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:41:57 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static int	get_texture_pixel_north(t_north *north, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = north->tex_n_data + (y * north->tex_n_size_line) + (x
			* (north->tex_n_bpp / 8));
	if (north->tex_n_bpp == 32)
	{
		if (north->tex_n_endian == 0)
			return (*(unsigned int *)pixel_addr);
		else
			return (((unsigned char)pixel_addr[0] << 24)
				| ((unsigned char)pixel_addr[1] << 16)
				| ((unsigned char)pixel_addr[2] << 8)
				| ((unsigned char)pixel_addr[3]));
	}
	else if (north->tex_n_bpp == 24)
		return (((unsigned char)pixel_addr[0])
			| ((unsigned char)pixel_addr[1] << 8)
			| ((unsigned char)pixel_addr[2] << 16));
	else
		return (0);
}

static int	get_texture_pixel_south(t_south *south, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = south->tex_s_data + (y * south->tex_s_size_line) + (x
			* (south->tex_s_bpp / 8));
	if (south->tex_s_bpp == 32)
	{
		if (south->tex_s_endian == 0)
			return (*(unsigned int *)pixel_addr);
		else
			return (((unsigned char)pixel_addr[0] << 24)
				| ((unsigned char)pixel_addr[1] << 16)
				| ((unsigned char)pixel_addr[2] << 8)
				| ((unsigned char)pixel_addr[3]));
	}
	else if (south->tex_s_bpp == 24)
		return (((unsigned char)pixel_addr[0])
			| ((unsigned char)pixel_addr[1] << 8)
			| ((unsigned char)pixel_addr[2] << 16));
	else
		return (0);
}

static int	get_texture_pixel_east(t_east *east, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = east->tex_e_data + (y * east->tex_e_size_line) + (x
			* (east->tex_e_bpp / 8));
	if (east->tex_e_bpp == 32)
	{
		if (east->tex_e_endian == 0)
			return (*(unsigned int *)pixel_addr);
		else
			return (((unsigned char)pixel_addr[0] << 24)
				| ((unsigned char)pixel_addr[1] << 16)
				| ((unsigned char)pixel_addr[2] << 8)
				| ((unsigned char)pixel_addr[3]));
	}
	else if (east->tex_e_bpp == 24)
		return (((unsigned char)pixel_addr[0])
			| ((unsigned char)pixel_addr[1] << 8)
			| ((unsigned char)pixel_addr[2] << 16));
	else
		return (0);
}

static int	get_texture_pixel_west(t_west *west, int x, int y)
{
	char	*pixel_addr;

	pixel_addr = west->tex_w_data + (y * west->tex_w_size_line) + (x
			* (west->tex_w_bpp / 8));
	if (west->tex_w_bpp == 32)
	{
		if (west->tex_w_endian == 0)
			return (*(unsigned int *)pixel_addr);
		else
			return (((unsigned char)pixel_addr[0] << 24)
				| ((unsigned char)pixel_addr[1] << 16)
				| ((unsigned char)pixel_addr[2] << 8)
				| ((unsigned char)pixel_addr[3]));
	}
	else if (west->tex_w_bpp == 24)
		return (((unsigned char)pixel_addr[0])
			| ((unsigned char)pixel_addr[1] << 8)
			| ((unsigned char)pixel_addr[2] << 16));
	else
		return (0);
}

int	get_texture_color(t_game *game, char direction, int tex_x, int tex_y)
{
	if (direction == 'N')
		return (get_texture_pixel_north(&game->north, tex_x, tex_y));
	else if (direction == 'S')
		return (get_texture_pixel_south(&game->south, tex_x, tex_y));
	else if (direction == 'E')
		return (get_texture_pixel_east(&game->east, tex_x, tex_y));
	else if (direction == 'W')
		return (get_texture_pixel_west(&game->west, tex_x, tex_y));
	else
		return (0);
}
