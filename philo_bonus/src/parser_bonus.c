/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 17:17:06 by preed             #+#    #+#             */
/*   Updated: 2022/06/18 21:11:29 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	parcer(int argc, char *argv[], t_philo *philo)
{
	philo->num_eat = -1;
	philo->stop = 0;
	if (argc < 5 || argc > 6)
		return (1);
	else
	{
		philo->philo_num = ft_atoi(argv[1]);
		philo->time_dead = ft_atoi(argv[2]);
		philo->time_eat = ft_atoi(argv[3]);
		philo->time_sleep = ft_atoi(argv[4]);
		if (argc == 6)
			philo->num_eat = ft_atoi(argv[5]);
	}
	if (philo->philo_num < 0 || philo->time_dead < 0
		|| philo->time_eat < 0 || philo->time_sleep < 0
		|| (philo->num_eat < 0 && philo->num_eat != -1))
		return (1);
	return (0);
}
