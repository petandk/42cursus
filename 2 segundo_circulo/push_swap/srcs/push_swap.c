/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:04:02 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/08 20:58:26 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	check_args(argc, argv);
	if (argc == 2 && argv[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (argc <= 1 || argc == 2)
		return (0);
	process_args(argc, argv);
	return (0);
}
