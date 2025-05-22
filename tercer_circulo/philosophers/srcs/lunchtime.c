/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:20:15 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/22 22:10:18 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;

	if (philo->id % 2 == 0)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(first_fork);
	ft_logging("has taken a fork", philo);
	pthread_mutex_lock(second_fork);
	ft_logging("has taken a fork", philo);
	philo->meals++;
	ft_logging("is eating", philo);
	philo->last_meal = ft_gettime_ms();
	usleep(philo->shared->times.eat_t * 1000);
	pthread_mutex_unlock(first_fork);
	pthread_mutex_unlock(second_fork);
}

static void	ft_sleep(t_philo *philo)
{
	ft_logging("is sleeping", philo);
	usleep(philo->shared->times.sleep_t * 1000);
}

void	croupier(t_table *table)
{
	int	i;
	int	fat_boys;
	int	num_ph;
	int	must_eat;

	num_ph = table->shared_data.times.num_philos;
	must_eat = table->shared_data.times.must_eat;
	while (table->shared_data.keep_eating)
	{
		i = 0;
		fat_boys = 0;
		while (i < num_ph)
		{
			if (ft_gettime_ms() - table->philos[i].last_meal > \
					(long long)table->philos[i].shared->times.die_t)
			{
				pthread_mutex_lock(&table->shared_data.death_mutex);
				table->shared_data.philo_died = 1;
				ft_logging("died", &table->philos[i]);
				pthread_mutex_unlock(&table->shared_data.death_mutex);
			}
			if (must_eat != -2 && table->philos[i].meals == must_eat)
				fat_boys++;
			if (fat_boys == num_ph
				|| table->shared_data.philo_died != 0)
			{
				pthread_mutex_lock(&table->shared_data.keep_eating_mutex);
				table->shared_data.keep_eating = 0;
				pthread_mutex_unlock(&table->shared_data.keep_eating_mutex);
			}
			i++;
		}
		usleep(10);
	}
}

void	*get_fat(void *arg)
{
	t_philo		*philo;
	int			is_ready;
	int			keep_going;

	philo = (t_philo *)arg;
	is_ready = 0;
	while (!is_ready)
	{
		pthread_mutex_lock(&philo->shared->ready_mutex);
		is_ready = philo->shared->ready;
		pthread_mutex_unlock(&philo->shared->ready_mutex);
		if (!is_ready)
			usleep(10);
	}
	pthread_mutex_lock(&philo->shared->keep_eating_mutex);
	keep_going = philo->shared->keep_eating;
	pthread_mutex_unlock(&philo->shared->keep_eating_mutex);
	while (keep_going)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_logging("is thinking", philo);
		pthread_mutex_lock(&philo->shared->keep_eating_mutex);
		keep_going = philo->shared->keep_eating;
		pthread_mutex_unlock(&philo->shared->keep_eating_mutex);
	}
	return (NULL);
}
