/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanzana <rmanzana@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 19:36:45 by rmanzana          #+#    #+#             */
/*   Updated: 2025/05/22 21:57:49 by rmanzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_times
{
	int	num_philos;
	int	die_t;
	int	eat_t;
	int	sleep_t;
	int	must_eat;
}	t_times;

typedef struct s_shared
{
	t_times			times;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	long long		start_time;
	int				philo_died;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	ready_mutex;
	int				ready;
	int				keep_eating;
	pthread_mutex_t	keep_eating_mutex;
}	t_shared;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal;
	int				meals;
	t_shared		*shared;
}	t_philo;

typedef struct s_table
{
	t_shared	shared_data;
	t_philo		*philos;
	pthread_t	*threads;
}	t_table;

// inits.c

int			init_times(t_times *times, int argc, char **argv);
int			init_shared(t_shared *shared, t_times times);
int			init_philosophers(t_table *table);

// inits2.c

int			init_table(t_table *table, int argc, char **argv);
int			init_threads(t_table *table);
void		wipe_table(t_table *table);
void		join_threads(t_table *table);

// maths.c

int			ft_notatoi(const char *str, int *error);
long long	ft_gettime_ms(void);

// test.c

void		print_times(t_times *times);

// error.c

void		print_error(char *type);

// strings.c

int			ft_notstrncmp(const char *s1, const char *s2, size_t n);
void		ft_logging(char *action, t_philo *philo);

// lunchtime.c

void		croupier(t_table *table);
void		*get_fat(void *arg);

#endif
