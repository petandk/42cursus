/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 11:25:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/03 11:28:54 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_window(t_window *win)
{
	if (!win)
		return ;
	if (win->frame)
		mlx_destroy_image(win->mlx, win->frame);
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
}
