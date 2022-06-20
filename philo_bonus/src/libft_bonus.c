/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:41:44 by preed             #+#    #+#             */
/*   Updated: 2022/06/19 19:41:04 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

long long int	find_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

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
