/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:15:23 by preed             #+#    #+#             */
/*   Updated: 2022/05/23 18:28:12 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	symbols_check(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	parcer(int argc, char *argv[], t_table *table)
{
	table->nte = 0;
	if (argc < 5 || argc > 6)
		return (1);
	else
	{
		table->all_philo = ft_atoi(argv[1]);
		table->time_die = ft_atoi(argv[2]);
		table->time_eat = ft_atoi(argv[3]);
		table->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			table->nte = ft_atoi(argv[5]);
	}
	if (table->all_philo < 0 || table->time_die < 0
		|| table->time_eat < 0 || table->time_sleep < 0
		|| table->nte < 0)
		return (1);
	return (0);
}
