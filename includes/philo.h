/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:16:35 by preed             #+#    #+#             */
/*   Updated: 2022/05/24 15:26:15 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_philo {
	int				philo_num;
	int				flag;
	int				time_to_die;
	int				nte;
	long			start;
	pthread_mutex_t	fork;
	pthread_t		tid;
}	t_philo;

typedef struct s_table {
	int				all_philo;
	int				idx;
	int				time_sleep;
	int				time_eat;
	int				time_fork;
	long			start;
	int				nte;
	int				time_die;
	pthread_mutex_t	print;
	t_philo			**philo;
}	t_table;

int		parcer(int argc, char *argv[], t_table *table);
int		ft_atoi(const char *str);
void	philo_init(t_table *table);

#endif