/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:06:35 by preed             #+#    #+#             */
/*   Updated: 2022/05/24 17:11:34 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_life(t_table *table)
{
	
}

void	philo_init(t_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(t_philo *) * table->all_philo);
	pthread_mutex_init(&table->print, NULL);
	while (i < table->all_philo)
	{
		table->philo[i] = malloc(sizeof(t_philo));
		table->philo[i]->philo_num = i + 1;
		pthread_mutex_init(&table->philo[i]->fork, NULL);
		table->philo[i]->flag = 0;
		i++;
	}
}