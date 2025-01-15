/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/15 20:49:35 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>

typedef struct s_philo
{
	int	id;
	int	fork;

}	t_philo;

typedef struct s_times
{
	int	num_p;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	must_eat;
}	t_times;

//maths.c
int		ft_atoi(const char *str);

//test.c
void	print_times(t_times *times);

#endif
