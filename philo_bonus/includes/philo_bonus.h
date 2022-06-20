/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:34:18 by preed             #+#    #+#             */
/*   Updated: 2022/06/19 19:25:50 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo {
	int				philo_num;
	int				time_dead;
	int				time_eat;
	int				time_sleep;
	int				num_eat;
	int				eat_count;
	int				stop;
	int				*pid;
	sem_t			*sem_printf;
	sem_t			*sem_data;
	sem_t			*sem_fork;
	sem_t			*sem_pulse;
	long long int	start_time;
	int				index;
	long long int	t_meal;
	pthread_t		check_monitor;
}	t_philo;

int				parcer(int argc, char *argv[], t_philo *philo);
void			philo_init(t_philo *philo);
void			create_fork(t_philo *philo);
void			ft_exit(t_philo *philo, const char *error, int i);
void			start(t_philo *philo);
void			print_msg(t_philo *p, const char *str);
void			ft_sleep(long long int time);
void			*check_dead_or_alive(void *arg);
int				ft_atoi(const char *str);
long long int	find_time(void);
void			exit_philo(t_philo *philo);
char			*make_name(char *name, int n);
int				ft_strlen(const char *str);
void			*wait_children(void *arg);

#endif
