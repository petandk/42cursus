/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:20:15 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/12 21:50:33 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *get_fat(void *arg)
{
	t_philo		*philo;
	long long	current_time;
	long long	time_passed;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->shared->ready);
	current_time = ft_gettime_ms();
	time_passed = current_time - philo->shared->start_time;
	pthread_mutex_lock(&philo->shared->print_mutex);
	printf("philo: %d, num philos: %d\n", philo->id, philo->shared->times.num_philos);
	printf("Time passed: %lld\n", time_passed);
	pthread_mutex_unlock(&philo->shared->print_mutex);
	
	return (NULL);
}
/*
void lunchtime(t_table *table)
{
	
}*/
