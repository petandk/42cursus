/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:49:15 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/31 18:32:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	ft_logging("has taken a fork", philo);
	usleep(philo->shared->times.die_t * 1000);
	pthread_mutex_unlock(philo->left_fork);
}

static void	asign_forks(t_philo *philo, pthread_mutex_t **fork_one, \
		pthread_mutex_t **fork_two)
{
	if (philo->id % 2 != 0)
	{
		*fork_one = philo->left_fork;
		*fork_two = philo->right_fork;
	}
	else
	{
		*fork_one = philo->right_fork;
		*fork_two = philo->left_fork;
	}
	pthread_mutex_lock(*fork_one);
	ft_logging("has taken a fork", philo);
	pthread_mutex_lock(*fork_two);
	ft_logging("has taken a fork", philo);
}

static void	actually_eat(t_philo *philo, pthread_mutex_t *fork_one, \
		pthread_mutex_t *fork_two)
{
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal = ft_gettime_ms();
	philo->meals++;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	ft_logging("is eating", philo);
	usleep(philo->shared->times.eat_t * 1000);
	pthread_mutex_unlock(fork_one);
	pthread_mutex_unlock(fork_two);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_t	*fork_one;
	pthread_mutex_t	*fork_two;

	if (philo->shared->times.num_philos == 1)
	{
		single_philo(philo);
		usleep(philo->shared->times.sleep_t * 1000);
		return ;
	}
	asign_forks(philo, &fork_one, &fork_two);
	actually_eat(philo, fork_one, fork_two);
}
