/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:41:45 by skim              #+#    #+#             */
/*   Updated: 2021/06/20 22:25:35 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	time;
	long			rt;

	gettimeofday(&time, NULL);
	rt = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (rt);
}

void	sem_print(t_philo *philo, char *s, int type)
{
	long	diff_time;

	sem_wait(philo->main->text);
	if (philo->philo_dead)
	{
		sem_post(philo->main->text);
		return ;
	}
	diff_time = get_time() - philo->main->start_time;
	printf("%dms\tPhilosopher(%d) : %s\n", \
	diff_time, philo->philo_num + 1, s);
	if (type)
		philo->philo_dead = 1;
	sem_post(philo->main->text);
}
