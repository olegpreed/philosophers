/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:17:28 by preed             #+#    #+#             */
/*   Updated: 2022/05/24 17:10:55 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pthread_run(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->all_philo)
	{
		if (pthread_create(&table->philo[i]->tid, NULL, philo_life, (void *) table);
	}
}

int	main(int argc, char *argv[])
{
	t_table	table;

	(void)table;
	if (!parcer(argc, argv, &table))
	{
		philo_init(&table);
		pthread_run(&table);
	}
	else
		printf("Error!\n");
	return (0);
}
