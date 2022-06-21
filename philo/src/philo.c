/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:06:35 by preed             #+#    #+#             */
/*   Updated: 2022/06/21 19:45:01 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_phil(t_philo *philo, const char *str)
{
	long long int	time;

	time = find_time();
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->data_mut);
	if (!philo->table->stop)
		printf("%lld %d %s\n", time - philo->table->start, \
		philo->philo_num, str);
	pthread_mutex_unlock(&philo->table->data_mut);
	pthread_mutex_unlock(&philo->table->print);
}

void	print_eating(t_philo *philo)
{
	long long int	time;

	time = find_time();
	pthread_mutex_lock(&philo->table->print);
	pthread_mutex_lock(&philo->table->data_mut);
	if (!philo->table->stop)
	{
		printf("%lld %d %s\n", time - philo->table->start \
			, philo->philo_num, "has taken a fork");
		printf("%lld %d %s\n", time - philo->table->start \
			, philo->philo_num, "is eating");
		philo->t_meal = find_time();
	}
	pthread_mutex_unlock(&philo->table->data_mut);
	pthread_mutex_unlock(&philo->table->print);
}

void	eat(t_philo *phil)
{
	pthread_mutex_lock(phil->lf);
	print_phil(phil, "has taken a fork");
	pthread_mutex_lock(phil->rf);
	print_eating(phil);
	ft_wait(phil->table->time_eat);
	pthread_mutex_lock(&phil->table->data_mut);
	phil->count_eat++;
	pthread_mutex_unlock(&phil->table->data_mut);
	pthread_mutex_unlock(phil->rf);
	pthread_mutex_unlock(phil->lf);
}

void	*philo_life(void *args)
{
	t_philo	*phil;

	phil = (t_philo *)args;
	while (1)
	{
		eat(phil);
		print_phil(phil, "is sleeping");
		ft_wait(phil->table->time_sleep);
		print_phil(phil, "is thinking");
	}	
	return (NULL);
}

int	philo_init(t_table *table)
{
	int	i;

	i = -1;
	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->all_philo);
	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) \
	* table->all_philo);
	while (++i < table->all_philo)
	{
		if (i == 0)
		{
			table->philo[i].lf = table->forks + table->all_philo - 1;
			table->philo[i].rf = table->forks + i;
		}
		else
		{
			table->philo[i].lf = table->forks + i - 1;
			table->philo[i].rf = table->forks + i;
		}
		table->philo[i].philo_num = i + 1;
		table->philo[i].count_eat = 0;
		table->philo[i].table = table;
		if (pthread_mutex_init(table->philo[i].lf, NULL))
			return (printf("ERROR: FAILED TO INIT MUTEX"));
	}
	return (0);
}
