/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 17:07:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/08/03 07:50:32 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

void	init_game(t_game *game, char *argv)
{
	game->map = parse_map_file(argv);
	init_game_error(game);
	init_player(&game->player, game->map->spawnpoint, game->map->spawn_dir);
	init_game_error(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Apple's cube");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line,
			&game->endian);
	game->click_to_rotate = CLICK_TO_ROTATE;
	game->shake_frames = 0;
	game->mini_map = 0;
	if (game->click_to_rotate)
		mlx_mouse_show(game->mlx, game->win);
	else
		mlx_mouse_hide(game->mlx, game->win);
	init_textures(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void	init_ray(t_ray *ray, t_player *player, float start_x)
{
	ray->ray_x = player->x;
	ray->ray_y = player->y;
	ray->cos_angle = cos(start_x);
	ray->sin_angle = sin(start_x);
	ray->dist = 0;
	ray->height = 0;
	ray->start_y = 0;
	ray->end = 0;
}
