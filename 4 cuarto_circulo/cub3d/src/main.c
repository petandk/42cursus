/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:15:05 by pamanzan          #+#    #+#             */
/*   Updated: 2025/07/31 16:15:16 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube_3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (show_error("usage"), 1);
	if (!check_extension(argv[1], ".cub"))
		return (show_error("map_extension"), 1);
	init_game(&game, argv[1]);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.win, 3, 1L << 1, key_release, &game);
	mlx_mouse_hook(game.win, mouse_press, &game);
	mlx_hook(game.win, 6, 1L << 6, mouse_move, &game);
	mlx_hook(game.win, 5, 1L << 3, mouse_release, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop_hook(game.mlx, draw_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
