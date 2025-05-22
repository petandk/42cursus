/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:41:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/22 20:59:51 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_notstrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		if ((unsigned char)s1[index] != (unsigned char)s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}

void	ft_logging(char *action, t_philo *philo)
{
	long long	now;
	long long	timestamp;

	if (philo->shared->keep_eating != 0)
	{
		pthread_mutex_lock(&philo->shared->print_mutex);
		now = ft_gettime_ms();
		timestamp = now - philo->shared->start_time;
		printf("%lld %d %s\n", timestamp, philo->id, action);
		pthread_mutex_unlock(&philo->shared->print_mutex);
	}
}
