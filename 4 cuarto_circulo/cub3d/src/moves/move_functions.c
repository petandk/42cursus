/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:16:26 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 16:17:22 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

static void	rotate_player(t_player *player)
{
	float	angle_speed;

	angle_speed = 0.03;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	move_player(t_player *player, t_game *game)
{
	int	speed;

	speed = 5;
	rotate_player(player);
	up_move(player, game, speed);
	down_move(player, game, speed);
	left_move(player, speed, game);
	right_move(player, speed, game);
}

static void	fill_shake_border(t_game *game, int offset, int bg_color)
{
	int	x;
	int	y;

	if (offset > 0)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			x = 0;
			while (x++ < offset)
				mlx_pixel_put(game->mlx, game->win, x, y, bg_color);
		}
	}
	else if (offset < 0)
	{
		y = 0;
		while (y++ < HEIGHT)
		{
			x = WIDTH + offset;
			while (x++ < WIDTH)
				mlx_pixel_put(game->mlx, game->win, x, y, bg_color);
		}
	}
}

void	render_frame(t_game *game, int shake)
{
	int	offset;
	int	bg_color;

	bg_color = rand() % 0xFFFFFF;
	if (shake)
	{
		if (rand() % 2)
			offset = 25;
		else
			offset = -25;
	}
	else
		offset = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->img, offset, 0);
	fill_shake_border(game, offset, bg_color);
}

void	draw_controls_label(t_game *game)
{
	static void	*controls_img;
	static int	img_width;
	static int	img_height;
	int			x;
	int			y;

	if (!controls_img)
	{
		controls_img = mlx_xpm_file_to_image(game->mlx, "./menu2.xpm",
				&img_width, &img_height);
		if (!controls_img)
		{
			printf("Error: Could not load menu.xpm\n");
			return ;
		}
	}
	x = WIDTH - img_width - 10;
	y = HEIGHT - img_height - 10;
	mlx_put_image_to_window(game->mlx, game->win, controls_img, x, y);
}
