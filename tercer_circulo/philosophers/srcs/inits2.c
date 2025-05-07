/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:11:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/07 22:17:40 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	t_times	times;

	if (!init_times(&times, argc, argv))
	{
		print_error("invalid_args");
		return (0);
	}
	if (!init_shared(&table->shared_data, times))
	{
		print_error("init_fail");
		return (0);
	}
	if (!init_philosophers(table))
	{
		free(table->shared_data.forks);
		pthread_mutex_destroy(&table->shared_data.print_mutex);
		pthread_mutex_destroy(&table->shared_data.death_mutex);
		print_error("init_fail");
		return (0);
	}
	return (1);
}

void	wipe_table(t_table *table)
{
	int	i;

	if (table->philos)
		free(table->philos);
	if (table->shared_data.forks)
	{
		i = 0;
		while (i < table->shared_data.times.num_philos)
		{
			pthread_mutex_destroy(&table->shared_data.forks[i]);
			i++;
		}
		free(table->shared_data.forks);
	}
	pthread_mutex_destroy(&table->shared_data.print_mutex);
	pthread_mutex_destroy(&table->shared_data.death_mutex);
}
