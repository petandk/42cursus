/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:43:40 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:51:51 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	init_dda_vars(t_dda_vars *v, t_ray *ray)
{
	v->hit = 0;
	v->side = 0;
	v->map_x = (int)(ray->ray_x / BLOCK);
	v->map_y = (int)(ray->ray_y / BLOCK);
	v->delta_dist_x = fabs(1.0f / ray->cos_angle);
	v->delta_dist_y = fabs(1.0f / ray->sin_angle);
}

static void	init_dda_steps(t_dda_vars *v, t_ray *ray)
{
	if (ray->cos_angle < 0)
	{
		v->step_x = -1;
		v->side_dist_x = (ray->ray_x - v->map_x * BLOCK) * v->delta_dist_x
			/ BLOCK;
	}
	else
	{
		v->step_x = 1;
		v->side_dist_x = ((v->map_x + 1) * BLOCK - ray->ray_x) * v->delta_dist_x
			/ BLOCK;
	}
	if (ray->sin_angle < 0)
	{
		v->step_y = -1;
		v->side_dist_y = (ray->ray_y - v->map_y * BLOCK) * v->delta_dist_y
			/ BLOCK;
	}
	else
	{
		v->step_y = 1;
		v->side_dist_y = ((v->map_y + 1) * BLOCK - ray->ray_y) * v->delta_dist_y
			/ BLOCK;
	}
}

static void	run_dda_loop(t_dda_vars *v, t_game *game)
{
	while (!v->hit)
	{
		if (v->side_dist_x < v->side_dist_y)
		{
			v->side_dist_x += v->delta_dist_x;
			v->map_x += v->step_x;
			v->side = 0;
		}
		else
		{
			v->side_dist_y += v->delta_dist_y;
			v->map_y += v->step_y;
			v->side = 1;
		}
		if (v->map_y >= 0 && v->map_x >= 0 && game->map->map[v->map_y]
			&& game->map->map[v->map_y][v->map_x] == '1')
			v->hit = 1;
	}
}

static void	set_dda_hit_result(t_dda_vars *v, t_ray *ray, t_render_column *rc)
{
	if (v->side == 0)
	{
		rc->hit_x = v->map_x * BLOCK;
		if (v->step_x < 0)
			rc->hit_x += BLOCK - 0.0001f;
		rc->hit_y = ray->ray_y + (rc->hit_x - ray->ray_x) * ray->sin_angle
			/ ray->cos_angle;
		rc->hit_vertical = 1;
	}
	else
	{
		rc->hit_y = v->map_y * BLOCK;
		if (v->step_y < 0)
			rc->hit_y += BLOCK - 0.0001f;
		rc->hit_x = ray->ray_x + (rc->hit_y - ray->ray_y) * ray->cos_angle
			/ ray->sin_angle;
		rc->hit_vertical = 0;
	}
}

void	perform_dda(t_ray *ray, t_game *game, t_render_column *rc)
{
	t_dda_vars	v;

	init_dda_vars(&v, ray);
	init_dda_steps(&v, ray);
	run_dda_loop(&v, game);
	set_dda_hit_result(&v, ray, rc);
}
