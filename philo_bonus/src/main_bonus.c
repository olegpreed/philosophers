/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 16:36:59 by preed             #+#    #+#             */
/*   Updated: 2022/06/19 20:03:07 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_philo	philo;

	if (parcer(argc, argv, &philo))
	{
		printf("Error!\n");
		return (0);
	}
	philo_init(&philo);
	create_fork(&philo);
	// exit_philo(&philo);
	sem_wait(philo.sem_pulse);
	ft_exit(&philo, "there was a tragedy", philo.philo_num - 1);
	return (0);
}