/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 17:00:16 by preed             #+#    #+#             */
/*   Updated: 2022/05/23 18:43:42 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_putnbr(const char *str, int i)
{
	long long int	num;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num > 2147483647)
			return (-1);
		num = 10 * num + (str[i] - 48);
		i++;
	}
	return ((int)num);
}

int	ft_atoi(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (ft_putnbr(str, i));
}
 