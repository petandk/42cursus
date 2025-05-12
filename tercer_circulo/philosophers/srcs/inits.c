/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:02:09 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/12 22:02:13 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_times(t_times *times, int argc, char **argv)
{
	int error;

	error = 0;
	times->num_philos = ft_notatoi(argv[1], &error);
	times->die_t = ft_notatoi(argv[2], &error);
	times->eat_t = ft_notatoi(argv[3], &error);
	times->sleep_t = ft_notatoi(argv[4], &error);
	if (argc == 6)
		times->must_eat = ft_notatoi(argv[5], &error);
	else
		times->must_eat = -2;
	if (error == -1)
		return (0);
	return (1);
}

static int	init_forks(t_shared *shared, int num_philos)
{
	int	i;

	shared->forks = malloc(sizeof(pthread_mutex_t) * num_philos);
	if (!shared->forks)
		return (0);
	i = 0;
	while (i < num_philos)
	{
		if (pthread_mutex_init(&shared->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&shared->forks[i]);
			free(shared->forks);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	init_global_mutex(t_shared *shared)
{
	if (pthread_mutex_init(&shared->print_mutex, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&shared->death_mutex, NULL) != 0)
	{
		pthread_mutex_destroy(&shared->print_mutex);
		return (0);
	}
	return (1);
}

int	init_shared(t_shared *shared, t_times times)
{
	shared->times = times;
	shared->start_time = 0;
	shared->philo_died = 0;
	if (!init_global_mutex(shared))
		return (0);
	if (!init_forks(shared, times.num_philos))
	{
		pthread_mutex_destroy(&shared->print_mutex);
		pthread_mutex_destroy(&shared->death_mutex);
		return (0);
	}
	return (1);
}

int	init_philosophers(t_table *table)
{
	int	i;
	int	num_philos;
	int	index;

	num_philos = table->shared_data.times.num_philos;
	table->philos = malloc(sizeof(t_philo) * num_philos);
	if (!table->philos)
		return (0);
	i = 0;
	while (i < num_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals = 0;
		table->philos[i].last_meal = 0;
		table->philos[i].right_fork = table->shared_data.forks[i];
		index = (i + 1) % num_philos;
		table->philos[i].left_fork = &table->shared_data.forks[index];
		table->philos[i].shared = &table->shared_data;
		i++;
	}
	return (1);
}
