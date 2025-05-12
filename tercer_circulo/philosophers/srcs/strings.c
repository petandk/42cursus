/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 18:41:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/10 20:09:40 by rmanzana         ###   ########.fr       */
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

void ft_logging(int id, int action)
{
	long long now;

	now = ft_gettime_ms();
	if (action == 0)
		printf("%lld %d has taken a fork", now, id);
	else if (action == 1)
		printf("%lld %d is eating", now, id);
	else if (action == 2)
		printf("%lld %d is sleeping", now, id);
	else if (action == 3)
		printf("%lld %d is thinking", now, id);
	else if (action == 4)
		printf("%lld %d died", now, id);
}
