/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:08:13 by skim              #+#    #+#             */
/*   Updated: 2021/06/19 20:26:01 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	philo_print(t_philo *philo, char *s, int type)
{
	int	diff;

	pthread_mutex_lock(&philo->main->text);
	if (philo->main->stop)
	{
		pthread_mutex_unlock(&philo->main->text);
		return ;
	}
	diff = get_time() - philo->main->start_time;
	ft_putnbr_fd(diff, 1);
	write(1, "ms\t Philosopher(", 16);
	ft_putnbr_fd(philo->philo_num + 1, 1);
	write(1, ") : ", 4);
	ft_putendl_fd(s, 1);
	if (type)
		philo->main->stop = 1;
	pthread_mutex_unlock(&philo->main->text);
}
