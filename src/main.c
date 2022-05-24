/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 19:17:28 by preed             #+#    #+#             */
/*   Updated: 2022/05/23 19:10:10 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table	table;

	(void)table;
	if (!parcer(argc, argv, &table))
	{
		philo_init(&table);
	}
	else
		printf("Error!\n");
	return (0);
}
