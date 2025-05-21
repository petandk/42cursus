/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:20:15 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/21 18:29:43 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void ft_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		ft_logging("took left fork", philo);
		pthread_mutex_lock(philo->left_fork);
		ft_logging("took right fork", philo);
		pthread_mutex_lock(philo->right_fork);
	}
	else
	{
		ft_logging("took right fork", philo);
		pthread_mutex_lock(philo->right_fork);
		ft_logging("took left fork", philo);
		pthread_mutex_lock(philo->left_fork);
	}
	ft_logging("is eating", philo);
	usleep(philo->shared->times.eat_t * 1000);
	philo->last_meal = ft_gettime_ms();
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
static void	ft_sleep(t_philo *philo)
{
	ft_logging("is sleeping", philo);
	usleep(philo->shared->times.sleep_t * 1000);
}

void	croupier( t_table *table)
{

}

void *get_fat(void *arg)
{
	t_philo		*philo;
	int			is_ready;
	int			meals;
	int			must_e;

	philo = (t_philo *)arg;
	is_ready = 0;
	meals = 0;
	while (!is_ready)
	{
		pthread_mutex_lock(&philo->shared->ready_mutex);
		is_ready = philo->shared->ready;
		pthread_mutex_unlock(&philo->shared->ready_mutex);
		if (!is_ready)
			usleep(10);	
	}
	must_e = philo->shared->times.must_eat;
	while (must_e == -2 || (must_e >= meals))
	{
		ft_eat(philo);
		meals++;
		ft_sleep(philo);
		ft_logging("is thinking", philo);
	}
	return (NULL);
}
