/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:39:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/22 20:43:48 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (print_error("invalid_args"), 1);
	if (!init_table(&table, argc, argv))
		return (1);
	if (!init_threads(&table))
		return (1);
	croupier(&table);
	join_threads(&table);
	wipe_table(&table);
	return (0);
}
