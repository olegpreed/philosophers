/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:16:35 by preed             #+#    #+#             */
/*   Updated: 2022/06/21 19:46:45 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

struct	s_table;

typedef struct s_philo {
	int				philo_num;
	int				count_eat;
	long long int	t_meal;
	long			start;
	struct s_table	*table;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
	pthread_t		tid;
}	t_philo;

typedef struct s_table {
	int				all_philo;
	int				time_sleep;
	int				time_eat;
	int				time_fork;
	int				time_die;
	long			start;
	int				nte;
	int				stop;
	pthread_t		check;
	pthread_mutex_t	print;
	pthread_mutex_t	data_mut;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}	t_table;

int				parcer(int argc, char *argv[], t_table *table);
int				ft_atoi(const char *str);
int				philo_init(t_table *table);
void			*philo_life(void *args);
long long int	find_time(void);
void			*check_dead_or_alive(void *args);
void			ft_wait(long long int time);
void			ft_free(t_table *table);
void			print_phil(t_philo *philo, const char *str);

#endif