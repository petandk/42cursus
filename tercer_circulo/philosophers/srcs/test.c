/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:31:08 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/15 20:40:10 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_times(t_times	*times)
{
	printf("Number of philosophers: %d\n", times->num_p);
	printf("Time to die: %d\n", times->die_t);
	printf("Time to eat: %d\n", times->eat_t);
	printf("Time to sleep: %d\n", times->sleep_t);
	if (times->must_eat != -1)
		printf("Every philosopher must eat %d times\n", times->must_eat);
	else
		printf("No limit to eat\n");
}
