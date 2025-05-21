/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:11:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/21 18:22:54 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_table(t_table *table, int argc, char **argv)
{
	t_times	times;

	if (!init_times(&times, argc, argv))
		return (0);
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

int	init_threads(t_table *table)
{
	int			num_th;
	int			i;
	
	num_th = table->shared_data.times.num_philos;
	table->threads = (pthread_t *)malloc(sizeof(pthread_t) * num_th);
	if (!table->threads)
		return (0);
	i = 0;
	while (i < num_th)
	{
		if (pthread_create(&table->threads[i], NULL, &get_fat, &table->philos[i]) != 0)
			return (0);
		i++;
	}
	pthread_mutex_lock(&table->shared_data.ready_mutex);
	table->shared_data.start_time = ft_gettime_ms();
	table->shared_data.ready = 1;
	pthread_mutex_unlock(&table->shared_data.ready_mutex);
	return (1);
}

void	wipe_table(t_table *table)
{
	int	i;

	if (table->philos)
	{
		free(table->philos);
		table->philos = NULL;
	}
	if (table->shared_data.forks)
	{
		i = 0;
		while (i < table->shared_data.times.num_philos)
		{
			pthread_mutex_destroy(&table->shared_data.forks[i]);
			i++;
		}
		free(table->shared_data.forks);
		table->shared_data.forks = NULL;
	}
	pthread_mutex_destroy(&table->shared_data.print_mutex);
	pthread_mutex_destroy(&table->shared_data.death_mutex);
	pthread_mutex_destroy(&table->shared_data.ready_mutex);
}

void	join_threads(t_table *table)
{
	int	i;
	int	num_th;

	num_th = table->shared_data.times.num_philos;
	i = 0;
	while (i < num_th)
	{
		if (pthread_join(table->threads[i], NULL) != 0)
			return ;
		i++;
	}
	free(table->threads);
	table->threads = NULL;
}
