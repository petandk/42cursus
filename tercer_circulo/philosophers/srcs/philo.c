/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:37:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/18 20:33:42 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_times	times;

	if (argc == 5 || argc == 6)
	{
		times.num_p = ft_notatoi(argv[1]);
		times.die_t = ft_notatoi(argv[2]);
		times.eat_t = ft_notatoi(argv[3]);
		times.sleep_t = ft_notatoi(argv[4]);
		if (argc == 6)
			times.must_eat = ft_notatoi(argv[5]);
		else
			times.must_eat = -2;
	}
	if (!(times.num_p == -1 || times.die_t == -1
			|| times.eat_t == -1 || times.sleep_t == -1
			|| times.must_eat == -1))
		create_philos(times);
	return (0);
}
