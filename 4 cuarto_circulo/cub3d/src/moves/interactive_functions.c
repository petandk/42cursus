/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive_functions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:34:20 by pamanzan          #+#    #+#             */
/*   Updated: 2025/08/03 11:05:44 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cube_3d.h"

/*
	returns a float with the direction, south by default
*/
static float	calc_direction(char spawndir)
{
	if (spawndir == 'N')
		return (PI / 2);
	else if (spawndir == 'S')
		return (3 * PI / 2);
	else if (spawndir == 'E')
		return (PI);
	else if (spawndir == 'W')
		return (0);
	else
		return (PI / 2);
}

void	init_player(t_player *player, t_point spawnpoint, char spawndir)
{
	player->x = (float)(BLOCK * spawnpoint.x) + (BLOCK / 2);
	player->y = (float)(BLOCK * spawnpoint.y) + (BLOCK / 2);
	player->angle = calc_direction(spawndir);
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == LEFT)
		game->player.left_rotate = true;
	if (keycode == RIGHT)
		game->player.right_rotate = true;
	if (keycode == ESC)
		close_window(game);
	if (keycode == N)
		toggle_mouse_mode(game);
	if (keycode == M)
		game->mini_map = !game->mini_map;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == D)
		game->player.key_right = false;
	if (keycode == LEFT)
		game->player.left_rotate = false;
	if (keycode == RIGHT)
		game->player.right_rotate = false;
	return (0);
}

int	close_window(t_game *game)
{
	free_map(game->map);
	free(game->map);
	printf("\033[1;92m");
	printf("████████ ██   ██  █████  ███    ██ ██   ██ ███████ ██ \n");
	printf("   ██    ██   ██ ██   ██ ████   ██ ██  ██  ██      ██ \n");
	printf("   ██    ███████ ███████ ██ ██  ██ █████   ███████ ██ \n");
	printf("   ██    ██   ██ ██   ██ ██  ██ ██ ██  ██       ██    \n");
	printf("   ██    ██   ██ ██   ██ ██   ████ ██   ██ ███████ ██ \n");
	printf("\033[0m");
	exit(0);
}
