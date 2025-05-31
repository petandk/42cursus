/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   croupier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:06:29 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/31 18:18:32 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_for_death(t_table *table, int i)
{
	pthread_mutex_lock(&table->philos[i].last_meal_mutex);
	if ((ft_gettime_ms() - table->philos[i].last_meal > \
		(long long)table->philos[i].shared->times.die_t)
		&& table->shared_data.keep_eating == 1)
	{
		pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
		pthread_mutex_lock(&table->shared_data.death_mutex);
		table->shared_data.philo_died = 1;
		pthread_mutex_unlock(&table->shared_data.death_mutex);
		ft_logging("died", &table->philos[i]);
		fat_enough(&table->shared_data);
		return (1);
	}
	pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
	return (0);
}

static int	monitor_philos(t_table *table)
{
	int	i;
	int	fat_boys;
	int	num_ph;
	int	must_eat;

	i = 0;
	fat_boys = 0;
	num_ph = table->shared_data.times.num_philos;
	must_eat = table->shared_data.times.must_eat;
	while (i < num_ph)
	{
		if (check_for_death(table, i))
			return (1);
		if (must_eat != -2 && table->philos[i].meals >= must_eat)
			fat_boys++;
		pthread_mutex_lock(&table->shared_data.death_mutex);
		if (fat_boys == num_ph
			|| table->shared_data.philo_died == 1)
			fat_enough(&table->shared_data);
		pthread_mutex_unlock(&table->shared_data.death_mutex);
		i++;
	}
	return (0);
}

void	croupier(t_table *table)
{
	while (still_hungry(&table->shared_data))
	{
		if (monitor_philos(table))
			return ;
		usleep(1000);
	}
}
