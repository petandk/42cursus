/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:16:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/30 18:49:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*fork_one;
	pthread_mutex_t	*fork_two;

	if (philo->shared->times.num_philos == 1)
	{
		pthread_mutex_lock (philo->left_fork);
		ft_logging("has taken a fork", philo);
		usleep(philo->shared->times.die_t * 1000);
		pthread_mutex_unlock(philo->left_fork);
		return ;
	}
	if (philo->id % 2 != 0)
	{
		fork_one = philo->left_fork;
		fork_two = philo->right_fork;
	}
	else
	{
		fork_one = philo->right_fork;
		fork_two = philo->left_fork;
	}
	pthread_mutex_lock(fork_one);
	ft_logging("has taken a fork", philo);
	pthread_mutex_lock(fork_two);
	ft_logging("has taken a fork", philo);
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = ft_gettime_ms();
	philo->meals++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	ft_logging("is eating", philo);
	usleep(philo->shared->times.eat_t * 1000);
	pthread_mutex_unlock(fork_one);
	pthread_mutex_unlock(fork_two);
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
	usleep(1000);
	while (still_hungry(&table->shared_data))
	{
		i = 0;
		fat_boys = 0;
		while (i < num_ph)
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
				return ;
			}
			else
				pthread_mutex_unlock(&table->philos[i].last_meal_mutex);
			if (must_eat != -2 && table->philos[i].meals >= must_eat)
				fat_boys++;
			pthread_mutex_lock(&table->shared_data.death_mutex);
			if (fat_boys == num_ph
				|| table->shared_data.philo_died == 1)
				fat_enough(&table->shared_data);
			pthread_mutex_unlock(&table->shared_data.death_mutex);

			i++;
		}
	
		usleep(1000);
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
	philo->last_meal = philo->shared->start_time;
	pthread_mutex_lock(&philo->shared->keep_eating_mutex);
	keep_going = philo->shared->keep_eating;
	pthread_mutex_unlock(&philo->shared->keep_eating_mutex);
	while (keep_going)
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_logging("is thinking", philo);
		usleep(500);
		keep_going = still_hungry(philo->shared);
	}
	return (NULL);
}
