/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:40:41 by preed             #+#    #+#             */
/*   Updated: 2022/06/20 20:34:50 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_dead_or_alive(void *arg)
{
	t_philo			*philo;
	long long int	time;

	philo = (t_philo *)arg;
	while (1)
	{
		time = find_time();
		if (time - philo->t_meal > philo->time_dead)
		{
			sem_wait(philo->sem_printf);
			printf("%lld %d %s\n", time - philo->start_time \
				, philo->index, "philo is dead");
			sem_post(philo->sem_stop);
			exit (0);
		}
	}
	return (NULL);
}

void	start(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_dead_or_alive, philo))
		ft_exit(philo, "ERROR: FAILED TO CREATE THREAD", philo->philo_num);
	pthread_detach(philo->check_monitor);
	while (1)
	{
		sem_wait(philo->sem_fork);
		print_msg(philo, "has taken a fork");
		sem_wait(philo->sem_fork);
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		ft_sleep(philo->time_eat);
		philo->t_meal = find_time();
		philo->eat_count++;
		if (philo->num_eat == philo->eat_count)
			sem_post(philo->sem_stuffed);
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		print_msg(philo, "is sleeping");
		ft_sleep(philo->time_sleep);
		print_msg(philo, "is thinking");
	}
}

void	init_sem(t_philo *philo)
{
	philo->pid = (int *)malloc(sizeof(int) * philo->philo_num);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_stop");
	sem_unlink("/sem_stuffed");
	philo->sem_printf = sem_open("/sem_print", O_CREAT, 0644, 1);
	philo->sem_stop = sem_open("/sem_stop", O_CREAT, 0644, 0);
	philo->sem_fork = sem_open("/sem_forks", O_CREAT, \
								0644, philo->philo_num);
	if (philo->num_eat)
		philo->sem_stuffed = sem_open("/sem_stuffed", O_CREAT, 0644, 0);
}
