/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 18:42:25 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 18:50:41 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube_3d.h"

// Normaliza un ángulo a [-PI, PI]
static float	normalize_angle(float angle)
{
	while (angle > PI)
		angle -= 2 * PI;
	while (angle < -PI)
		angle += 2 * PI;
	return (angle);
}

// AQUI MANEJAMOS EL EFECTO DE OJO DE PEZ
float	fixed_dist( t_render_column *rc, t_game *game)
{
	float	delta_x;
	float	delta_y;
	float	raw_dist;
	float	diff;
	float	fix_dist;

	delta_x = rc->hit_x - game->player.x;
	delta_y = rc->hit_y - game->player.y;
	raw_dist = sqrtf(delta_x * delta_x + delta_y * delta_y);
	diff = normalize_angle(game->ray.ray_angle - game->player.angle);
	fix_dist = raw_dist * cosf(diff);
	if (fabsf(diff) < 0.0001f)
		fix_dist = raw_dist;
	if (fix_dist < 0.2f)
		fix_dist = 0.2f;
	return (fix_dist);
}

void	calc_ray_hit_and_dist(t_game *game, t_render_column *rc)
{
	perform_dda(&game->ray, game, rc);
	rc->corrected_dist = fixed_dist(rc, game);
	if (rc->corrected_dist < 0.0001)
		rc->corrected_dist = 0.0001;
	game->ray.dist = rc->corrected_dist;
}
