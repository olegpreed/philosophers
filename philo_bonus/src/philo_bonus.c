/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:40:41 by preed             #+#    #+#             */
/*   Updated: 2022/06/19 20:06:53 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	dead_or_fed(t_philo *philo)
{
	int				i;
	long long int	time;

	time = find_time();
	i = -1;
	if (time - philo->t_meal > philo->time_dead)
	{
		printf("%lld %d %s\n", time - philo->start_time \
			, philo->index, "philo is dead");
		return (1);
	}
	if (philo->eat_count == philo->num_eat)
		return (2);
	return (0);
}

void	*check_dead_or_alive(void *arg)
{
	t_philo	*philo;
	char	*name;
	int		n;

	n = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sem_printf);
		sem_wait(philo->sem_data);
		n = dead_or_fed(philo);
		if (n)
			break ;
		sem_post(philo->sem_data);
		sem_post(philo->sem_printf);
		usleep(1000); //why
	}
	if (n == 1)
		sem_post(philo->sem_pulse);
	if (n == 2)
	{
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
	}
	sem_close(philo->sem_data);
	name = make_name("philo", philo->index);
	sem_unlink(name);
	free(name);
	printf("%d IS NOT HUNGRY %d\n", philo->index, n);
	exit (0);
	return (NULL);
}

void	start(t_philo *philo)
{
	if (pthread_create(&philo->check_monitor, \
			NULL, &check_dead_or_alive, philo))
		ft_exit(philo, "ERROR: FAILED TO CREATE THREAD", philo->philo_num - 1);
	pthread_detach(philo->check_monitor);
	while (1)
	{
		sem_wait(philo->sem_fork);
		print_msg(philo, "has taken a fork");
		sem_wait(philo->sem_fork);
		print_msg(philo, "has taken a fork");
		print_msg(philo, "is eating");
		ft_sleep(philo->time_eat);
		sem_wait(philo->sem_data);
		philo->t_meal = find_time();
		philo->eat_count++;
		sem_post(philo->sem_data);
		sem_post(philo->sem_fork);
		sem_post(philo->sem_fork);
		print_msg(philo, "is sleeping");
		ft_sleep(philo->time_sleep);
		print_msg(philo, "is thinking");
	}
}

void	create_fork(t_philo *philo)
{
	int			i;
	char		*name;
	pthread_t	tid;

	i = -1;
	philo->start_time = find_time();
	while (++i < philo->philo_num)
	{
		philo->pid[i] = fork();
		if (philo->pid[i] == -1)
			ft_exit(philo, "ERROR: FAILED TO CREATE FORK", i);
		if (philo->pid[i] == 0)
		{
			philo->index = i + 1;
			name = make_name("philo", philo->index);
			philo->sem_data = sem_open(name, 0644, 1); // why
			free(name);
			philo->t_meal = find_time();
			start(philo);
			return ;
		}
	}
	pthread_create(&tid, NULL, wait_children, (void *)philo);
	pthread_detach(tid);
}

void	philo_init(t_philo *philo)
{
	philo->pid = (int *)malloc(sizeof(int) * philo->philo_num);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_pulse");
	philo->sem_printf = sem_open("/sem_print", O_CREAT, 0644, 1);
	philo->sem_pulse = sem_open("/sem_pulse", O_CREAT, 0644, 0);
	philo->sem_fork = sem_open("/sem_forks", O_CREAT, \
								0644, philo->philo_num);
	if (philo->sem_printf <= 0 || philo->sem_fork <= 0 || philo->sem_fork <= 0)
	{
		free(philo->pid);
		printf("ERROR: SEMAPHORE OPEN"); // why
	}
}
