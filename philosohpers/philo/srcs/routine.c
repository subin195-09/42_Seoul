/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:58:06 by skim              #+#    #+#             */
/*   Updated: 2021/06/20 23:00:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->fork[philo->l_fork]);
	philo_print(philo, "pick_up fork", 0);
	pthread_mutex_lock(&philo->main->fork[philo->r_fork]);
	philo_print(philo, "pick_up fork", 0);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&(philo->mutex_eat));
	philo_print(philo, "eating", 0);
	philo->philo_time = get_time();
	pthread_mutex_unlock(&(philo->mutex_eat));
	while (!philo->main->stop && \
	get_time() - philo->philo_time <= philo->main->arg_info.time_to_eat)
		usleep(1000);
	philo->count_eat++;
}

void	return_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->main->fork[philo->l_fork]);
	pthread_mutex_unlock(&philo->main->fork[philo->r_fork]);
}

void	sleeping(t_philo *philo)
{
	int	time;

	philo_print(philo, "sleeping", 0);
	time = get_time();
	while (!philo->main->stop && \
	get_time() - time <= philo->main->arg_info.time_to_sleep)
		usleep(1000);
}
