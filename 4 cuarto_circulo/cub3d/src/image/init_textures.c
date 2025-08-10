/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:05:16 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 19:01:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	init_north_texture(t_game *game)
{
	game->north.tex_n = mlx_xpm_file_to_image(game->mlx, game->map->no_texture,
			&game->tex_width, &game->tex_height);
	if (game->north.tex_n == NULL)
		error_load_textures(game);
	game->north.tex_n_data = mlx_get_data_addr(game->north.tex_n,
			&game->north.tex_n_bpp, &game->north.tex_n_size_line,
			&game->north.tex_n_endian);
	game->north.tex_n_width = game->tex_width;
	game->north.tex_n_height = game->tex_height;
}

static void	init_south_texture(t_game *game)
{
	game->south.tex_s = mlx_xpm_file_to_image(game->mlx, game->map->so_texture,
			&game->tex_width, &game->tex_height);
	if (game->south.tex_s == NULL)
		error_load_textures(game);
	game->south.tex_s_data = mlx_get_data_addr(game->south.tex_s,
			&game->south.tex_s_bpp, &game->south.tex_s_size_line,
			&game->south.tex_s_endian);
	game->south.tex_s_width = game->tex_width;
	game->south.tex_s_height = game->tex_height;
}

static void	init_east_texture(t_game *game)
{
	game->east.tex_e = mlx_xpm_file_to_image(game->mlx, game->map->ea_texture,
			&game->tex_width, &game->tex_height);
	if (game->east.tex_e == NULL)
		error_load_textures(game);
	game->east.tex_e_data = mlx_get_data_addr(game->east.tex_e,
			&game->east.tex_e_bpp, &game->east.tex_e_size_line,
			&game->east.tex_e_endian);
	game->east.tex_e_width = game->tex_width;
	game->east.tex_e_height = game->tex_height;
}

static void	init_west_texture(t_game *game)
{
	game->west.tex_w = mlx_xpm_file_to_image(game->mlx, game->map->we_texture,
			&game->tex_width, &game->tex_height);
	if (game->west.tex_w == NULL)
		error_load_textures(game);
	game->west.tex_w_data = mlx_get_data_addr(game->west.tex_w,
			&game->west.tex_w_bpp, &game->west.tex_w_size_line,
			&game->west.tex_w_endian);
	game->west.tex_w_width = game->tex_width;
	game->west.tex_w_height = game->tex_height;
}

void	init_textures(t_game *game)
{
	init_north_texture(game);
	init_south_texture(game);
	init_east_texture(game);
	init_west_texture(game);
}
