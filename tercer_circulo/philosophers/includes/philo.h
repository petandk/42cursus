/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/01/18 20:32:24 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_philo
{
	int	id;
	int	l_fork;
	int	r_fork;
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
int		ft_notatoi(const char *str);

//test.c
void	print_times(t_times *times);

//error.c
void	print_error(char*type);

//strings.c
int		ft_notstrncmp(const char *s1, const char *s2, size_t n);

#endif
