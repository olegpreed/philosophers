/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:17:28 by preed             #+#    #+#             */
/*   Updated: 2022/06/21 19:48:00 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pthread_run(t_table *table)
{
	int	i;

	i = 0;
	table->start = find_time();
	while (i < table->all_philo)
	{
		table->philo[i].start = find_time();
		table->philo[i].t_meal = find_time();
		if (pthread_create(&table->philo[i].tid, NULL, &philo_life, (void *) \
		(table->philo + i)))
		{
			ft_free(table);
			return (1);
		}
		pthread_detach(table->philo[i].tid);
		usleep(50);
		i++;
	}
	if (pthread_create(&table->check, NULL, &check_dead_or_alive, table->philo))
	{
		ft_free(table);
		return (1);
	}
	pthread_join(table->check, NULL);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (!parcer(argc, argv, &table))
	{
		if (pthread_mutex_init(&table.print, NULL)
			|| pthread_mutex_init(&table.data_mut, NULL))
		{
			printf("ERROR: FAILED TO INIT MUTEX");
			return (1);
		}
		if (philo_init(&table))
		{
			ft_free(&table);
			return (1);
		}
		if (pthread_run(&table))
		{
			printf("ERROR: FAILED TO CREATE THREAD");
			return (1);
		}
		ft_free(&table);
	}
	else
		printf("Error!\n");
	return (0);
}
