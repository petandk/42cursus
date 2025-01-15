/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:37:42 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/15 20:39:45 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_times	times;

	if (argc == 5 || argc == 6)
	{
		times.num_p = ft_atoi(argv[1]);
		times.die_t = ft_atoi(argv[2]);
		times.eat_t = ft_atoi(argv[3]);
		times.sleep_t = ft_atoi(argv[4]);
		if (argc == 6)
			times.must_eat = ft_atoi(argv[5]);
		else
			times.must_eat = -1;
	}
	print_times(&times);
	return (0);
}
