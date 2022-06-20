/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:59 by preed             #+#    #+#             */
/*   Updated: 2022/06/20 20:38:34 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*are_you_hungry(void *arg)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)arg;
	while (++i < philo->philo_num)
		sem_wait(philo->sem_stuffed);
	sem_post(philo->sem_stop);
	return (NULL);
}

int	hunger_meter(t_philo *philo)
{
	pthread_t	tid;

	if (philo->num_eat)
	{
		if (pthread_create(&tid, NULL, &are_you_hungry, philo))
			ft_exit(philo, "ERROR: FAILED TO CREATE THREAD", 0);
		pthread_detach(tid);
	}
	return (0);
}

void	create_fork(t_philo *philo)
{
	int	i;

	i = -1;
	philo->start_time = find_time();
	while (++i < philo->philo_num)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			ft_exit(philo, "ERROR: FAILED TO CREATE FORK", i + 1);
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			philo->t_meal = find_time();
			start(philo);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if (parcer(argc, argv, &philo))
	{
		printf("Error!\n");
		return (1);
	}
	init_sem(&philo);
	hunger_meter(&philo);
	create_fork(&philo);
	sem_wait(philo.sem_stop);
	ft_exit(&philo, NULL, philo.philo_num);
	return (0);
}
