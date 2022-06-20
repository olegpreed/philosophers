/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preed <preed@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:20:45 by preed             #+#    #+#             */
/*   Updated: 2022/06/19 19:58:32 by preed            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*wait_children(void *arg)
{
	int		i;
	t_philo	*philo;

	i = -1;
	philo = (t_philo *)arg;
	while (++i < philo->philo_num)
		waitpid(philo->pid[i], NULL, 0);
	exit(0);
}

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

// void	say_goodbye(t_philo *philo)
// {
// 	int		i;
// 	int		status;

// 	i = 0;
// 	while (i < philo->philo_num)
// 		waitpid(philo->pid[i++], &status, 0);
// 	i = -1;
// 	while (++i < philo->philo_num)
// 		kill(philo->pid[i], SIGKILL);
// }

void	ft_exit(t_philo *philo, const char *error, int i)
{
	int	j;

	j = -1;
	while (++j <= i)
		kill(philo->pid[j], SIGKILL);
	sem_close(philo->sem_printf);
	sem_close(philo->sem_fork);
	sem_unlink("/sem_print");
	sem_unlink("/sem_forks"); // why
	free(philo->pid);
	if (error)
		printf("%s\n", error);
	exit(0);
}

void	print_msg(t_philo *philo, const char *str)
{
	long long int	time;

	time = find_time();
	sem_wait(philo->sem_printf);
	sem_wait(philo->sem_data);
	if (!philo->stop)
		printf("%lld %d %s\n", time - philo->start_time, philo->index, str);
	sem_post(philo->sem_data);
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