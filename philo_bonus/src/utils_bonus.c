/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:20:45 by preed             #+#    #+#             */
/*   Updated: 2022/06/20 20:46:54 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*make_name(char *name, int n)
{
	char	*result;
	int		num;
	int		i;

	i = 0;
	num = n;
	while (num)
	{
		num /= 10;
		++i;
	}
	result = malloc(sizeof(char) * (i + ft_strlen(name) + 1));
	if (result == NULL)
		return (NULL);
	num = -1;
	while (++num < i)
		result[num] = name[num];
	while (n)
	{
		result[i++] = n % 10 + '0';
		n /= 10;
	}
	result[i] = 0;
	return (result);
}

void	ft_exit(t_philo *philo, const char *error, int i)
{
	int	j;

	j = -1;
	if (i)
		while (++j < i)
			kill(philo->pid[j], SIGKILL);
	sem_close(philo->sem_printf);
	sem_close(philo->sem_fork);
	sem_close(philo->sem_stop);
	if (philo->num_eat != -1)
		sem_close(philo->sem_stuffed);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks");
	sem_unlink("/sem_stuffed");
	sem_unlink("/sem_stop");
	free(philo->pid);
	if (error)
		printf("%s\n", error);
	exit (0);
}

void	print_msg(t_philo *philo, const char *str)
{
	long long int	time;

	time = find_time();
	sem_wait(philo->sem_printf);
	printf("%lld %d %s\n", time - philo->start_time, philo->index, str);
	sem_post(philo->sem_printf);
}

void	ft_sleep(long long int time)
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
