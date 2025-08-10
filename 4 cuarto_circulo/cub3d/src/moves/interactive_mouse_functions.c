/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_mouse_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:16:45 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 16:17:46 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

int	mouse_press(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (!game->click_to_rotate)
		return (0);
	if (button == 1)
		game->player.left_rotate = true;
	if (button == 3)
		game->player.right_rotate = true;
	return (0);
}

int	mouse_release(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (!game->click_to_rotate)
		return (0);
	if (button == 1)
		game->player.left_rotate = false;
	if (button == 3)
		game->player.right_rotate = false;
	return (0);
}

void	toggle_mouse_mode(t_game *game)
{
	game->click_to_rotate = !game->click_to_rotate;
	if (game->click_to_rotate)
	{
		mlx_mouse_show(game->mlx, game->win);
		game->player.left_rotate = false;
		game->player.right_rotate = false;
	}
	else
		mlx_mouse_hide(game->mlx, game->win);
}

static int	mouse_move_free(int x, int y, t_game *game)
{
	static int	initialized;
	int			dx;
	int			center_x;
	int			center_y;

	(void)y;
	center_x = WIDTH / 2;
	center_y = HEIGHT / 2;
	if (!initialized)
	{
		initialized = 1;
		return (0);
	}
	dx = x - center_x;
	game->player.angle += dx * 0.001f;
	mlx_mouse_move(game->mlx, game->win, center_x, center_y);
	return (0);
}

int	mouse_move(int x, int y, t_game *game)
{
	static int	prev_x;
	static int	initialized;
	int			dx;

	(void)y;
	if (!game->click_to_rotate)
		return (mouse_move_free(x, y, game));
	if (!initialized)
	{
		prev_x = x;
		initialized = 1;
		return (0);
	}
	if (!game->player.left_rotate && !game->player.right_rotate)
	{
		prev_x = x;
		return (0);
	}
	dx = x - prev_x;
	game->player.angle += dx * 0.003f;
	prev_x = x;
	return (0);
}
