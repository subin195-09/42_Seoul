/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 22:50:25 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:29:02 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	get_fork(t_philo *philo)
{
	sem_wait(philo->main->fork);
	philo_print(philo, "pick_up fork", 0);
	sem_wait(philo->main->fork);
	philo_print(philo, "pick_up fork", 0);
}

void	eat(t_philo *philo)
{
	sem_wait(philo->sem_eat);
	philo_print(philo, "eating", 0);
	philo->philo_time = get_time();
	sem_post(philo->sem_eat);
	while (!philo->philo_died && \
	get_time() - philo->philo_time <= philo->main->arg_info.time_to_eat)
		usleep(1000);
	philo->count_eat++;
}

void	return_fork(t_philo *philo)
{
	sem_post(philo->main->fork);
	sem_post(philo->main->fork);
}

void	sleeping(t_philo *philo)
{
	int	time;

	philo_print(philo, "sleeping", 0);
	time = get_time();
	while (!philo->philo_died && \
	get_time() - time <= philo->main->arg_info.time_to_sleep)
		usleep(1000);
}
