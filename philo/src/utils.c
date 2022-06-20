/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:00:16 by preed             #+#    #+#             */
/*   Updated: 2022/06/06 13:36:17 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_he_breathing(t_philo *philo)
{
	int				i;
	int				well_fed_phil;
	long long int	time;

	time = find_time();
	well_fed_phil = 0;
	i = -1;
	while (++i < philo->table->all_philo)
	{
		if (time - philo[i].t_meal > philo->table->time_die)
		{
			philo->table->stop = 1;
			printf("%lld %d %s\n", time - philo->table->start \
				, philo[i].philo_num, "is dead");
			return (1);
		}
		if (philo->table->nte != -1)
		{
			if ((philo + i)->count_eat >= philo->table->nte)
				well_fed_phil++;
			if ((i + 1) == philo->table->all_philo
				&& well_fed_phil == philo->table->all_philo)
				return (philo->table->stop = 1);
		}
	}
	return (0);
}

void	*check_dead_or_alive(void *args)
{
	t_philo			*philo;

	philo = (t_philo *)args;
	while (1)
	{
		pthread_mutex_lock(&philo->table->data_mut);
		if (is_he_breathing(philo))
			return (NULL);
		pthread_mutex_unlock(&philo->table->data_mut);
		usleep(1000);
	}
	return (NULL);
}

long long int	find_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_wait(long long int time)
{
	long long int	tmp;

	tmp = find_time();
	while (1)
	{
		if ((find_time() - tmp) >= time)
			break ;
		usleep(100);
	}
}

void	ft_free(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->all_philo)
		pthread_mutex_destroy(table->philo[i].lf);
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->data_mut);
	free(table->forks);
	free(table->philo);
}
