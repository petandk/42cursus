/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:16:51 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/04 16:47:17 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_menu(void)
{
	write(2, "Please run ./fractol followed by:\n", 34);
	write(2, "\"mandelbrot\" to view the mandelbrot fractal\n", 44);
	write(2, "\"julia\" followed by some constants ", 35);
	write(2, "to view different julia fractals\n", 33);
	write(2, "Some cool julia constants to try:\n", 35);
	write(2, "-0.4 0.6\n", 9);
	write(2, "0.285 0.01\n", 11);
	write(2, "-0.8 0.156\n", 11);
	write(2, "-0.7269 0.1889\n", 15);
}

int	check_mandelbrot(int argc)
{
	if (argc != 2)
	{
		write(2, "Mandelbrot set doesn't take parameters\n", 39);
		return (0);
	}
	return (1);
}

int	check_julia(int argc, char *argv[], t_complex *julia_const)
{
	if (argc != 4)
	{
		write(2, "\"julia\" set needs 2 parameters\n", 31);
		return (0);
	}
	return (julia_pars(argv[2], argv[3], julia_const));
}

int	check_args(int argc, char *argv[], t_complex *julia_const)
{
	if (argc == 1 || (argc > 1 && argv[1][0] == '\0'))
	{
		print_menu();
		return (0);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0)
		return (check_mandelbrot(argc));
	if (ft_strncmp(argv[1], "julia", 5) == 0)
		return (check_julia(argc, argv, julia_const));
	write(2, "Invalid fractal type\n", 21);
	return (0);
}
