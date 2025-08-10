/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_tex_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:17:03 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:23:53 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	calc_tex_x_east(t_game *game, t_render_column *rc)
{
	rc->tex_x = (int)(rc->wall_hit * game->east.tex_e_width);
	if (rc->tex_x >= game->east.tex_e_width)
		rc->tex_x = game->east.tex_e_width - 1;
}

static void	calc_tex_x_west(t_game *game, t_render_column *rc)
{
	rc->tex_x = game->west.tex_w_width - (int)(rc->wall_hit
			* game->west.tex_w_width) - 1;
	if (rc->tex_x >= game->west.tex_w_width)
		rc->tex_x = game->west.tex_w_width - 1;
}

static void	calc_tex_x_north(t_game *game, t_render_column *rc)
{
	rc->tex_x = (int)(rc->wall_hit * game->north.tex_n_width);
	if (rc->tex_x >= game->north.tex_n_width)
		rc->tex_x = game->north.tex_n_width - 1;
}

static void	calc_tex_x_south(t_game *game, t_render_column *rc)
{
	rc->tex_x = game->south.tex_s_width - (int)(rc->wall_hit
			* game->south.tex_s_width) - 1;
	if (rc->tex_x >= game->south.tex_s_width)
		rc->tex_x = game->south.tex_s_width - 1;
}

void	calc_tex_x(t_game *game, t_render_column *rc)
{
	if (rc->direction == 'E')
		calc_tex_x_east(game, rc);
	else if (rc->direction == 'W')
		calc_tex_x_west(game, rc);
	else if (rc->direction == 'S')
		calc_tex_x_south(game, rc);
	else
		calc_tex_x_north(game, rc);
}
