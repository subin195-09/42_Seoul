/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 21:08:13 by skim              #+#    #+#             */
/*   Updated: 2021/06/18 15:55:57 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			rt;

	gettimeofday(&time, NULL);
	rt = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (rt);
}

void	philo_print(t_philo *philo, char *s)
{
	long	diff;

	pthread_mutex_lock(&philo->main->text);
	diff = get_time() - philo->main->start_time;
	printf("%ldms\t Philosopher(%d) : %s\n", diff, philo->philo_num + 1, s);
	if (philo->main->stop)
		return ;
	pthread_mutex_unlock(&philo->main->text);
}
