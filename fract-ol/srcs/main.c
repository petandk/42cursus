/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 23:04:58 by rmanzana          #+#    #+#             */
/*   Updated: 2024/12/15 00:18:46 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_window	window;
	
	window.mlx = mlx_init();
	if (!window.mlx)
		return (1);
	window.win = mlx_new_window(window.mlx, WIDTH, HEIGHT, "My first window");
	if (!window.win)
		return (1);
	window.frame = mlx_new_image(window.mlx, WIDTH, HEIGHT);
	window.image = mlx_get_data_addr(window.frame, &window.bits_per_px, &window.line_length, &window.endian);
	//paint_pixel(&window, 50, 50, 0xFF0000);
 	paint_line(&window, 0, HEIGHT / 2, WIDTH, HEIGHT / 2, 0x00FF00);
	paint_line(&window, WIDTH / 2, 0, WIDTH / 2, HEIGHT, 0xFF0000);
	mlx_put_image_to_window(window.mlx, window.win, window.frame, 0, 0);
	mlx_key_hook(window.win, key_handler, &window);
	mlx_hook(window.win, DESTROY_WINDOW, 0, click_x, &window);
	mlx_loop(window.mlx);
	return (0);
}
