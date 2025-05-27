/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunchtime_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 18:50:06 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/27 18:54:12 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	still_hungry(t_shared *shared)
{
	int	hungry;

	pthread_mutex_lock(&shared->keep_eating_mutex);
	hungry = shared->keep_eating;
	pthread_mutex_unlock(&shared->keep_eating_mutex);
	return (hungry);
}

void	fat_enough(t_shared *shared)
{
	pthread_mutex_lock(&shared->keep_eating_mutex);
	shared->keep_eating = 0;
	pthread_mutex_unlock(&shared->keep_eating_mutex);
}

