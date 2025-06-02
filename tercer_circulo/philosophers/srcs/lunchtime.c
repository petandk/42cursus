/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:16:17 by rmanzana          #+#    #+#             */
/*   Updated: 2025/06/02 18:51:01 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_sleep(t_philo *philo)
{
	ft_logging("is sleeping", philo);
	usleep(philo->shared->times.sleep_t * 1000);
}

static void	wait_for_it(t_philo *philo)
{
		pthread_mutex_lock(&philo->shared->ready_mutex);
		pthread_mutex_unlock(&philo->shared->ready_mutex);
}

static void	cycle_of_life(t_philo *philo)
{
	int	keep_going;

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
}

void	*get_fat(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	wait_for_it(philo);
	cycle_of_life(philo);
	return (NULL);
}
