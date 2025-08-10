/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:05:53 by rmanzana          #+#    #+#             */
/*   Updated: 2025/07/31 18:29:35 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

int	check_hit_vertical(t_ray *ray)
{
	if (fabs(ray->cos_angle) > fabs(ray->sin_angle))
		return (1);
	else
		return (0);
}

char	get_wall_direction(t_ray *ray)
{
	if (check_hit_vertical(ray))
	{
		if (ray->cos_angle > 0)
			return ('E');
		else
			return ('O');
	}
	else
	{
		if (ray->sin_angle > 0)
			return ('S');
		else
			return ('N');
	}
}

void	set_tex_h(t_game *game, t_render_column *rc)
{
	if (rc->direction == 'E')
		rc->tex_h = game->east.tex_e_height;
	else if (rc->direction == 'W')
		rc->tex_h = game->west.tex_w_height;
	else if (rc->direction == 'S')
		rc->tex_h = game->south.tex_s_height;
	else
		rc->tex_h = game->north.tex_n_height;
}

void	clamp_tex_y(t_game *game, t_render_column *rc)
{
	if (rc->direction == 'E' && rc->tex_y >= game->east.tex_e_height)
		rc->tex_y = game->east.tex_e_height - 1;
	if (rc->direction == 'W' && rc->tex_y >= game->west.tex_w_height)
		rc->tex_y = game->west.tex_w_height - 1;
	if (rc->direction == 'S' && rc->tex_y >= game->south.tex_s_height)
		rc->tex_y = game->south.tex_s_height - 1;
	if (rc->direction == 'N' && rc->tex_y >= game->north.tex_n_height)
		rc->tex_y = game->north.tex_n_height - 1;
}
