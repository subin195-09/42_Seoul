/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:58:06 by skim              #+#    #+#             */
/*   Updated: 2021/06/18 16:17:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	// if (philo->philo_num != (philo->main->arg_info.num_of_philo - 1))
	if (philo->philo_num % 2)
	{
		pthread_mutex_lock(&philo->main->fork[philo->l_fork]);
		philo_print(philo, "pick_up fork");
		pthread_mutex_lock(&philo->main->fork[philo->r_fork]);
		philo_print(philo, "pick_up fork");
	}
	else
	{
		pthread_mutex_lock(&philo->main->fork[philo->r_fork]);
		philo_print(philo, "pick_up fork");
		pthread_mutex_lock(&philo->main->fork[philo->l_fork]);
		philo_print(philo, "pick_up fork");
	}
}

void	eat(t_philo *philo)
{
	philo->philo_time = get_time();
	philo_print(philo, "eating");
	usleep(1000 * philo->main->arg_info.time_to_eat);
	philo->count_eat++;
}

void	return_fork(t_philo *philo)
{
	// if (philo->philo_num != philo->main->arg_info.num_of_philo - 1)
	if (philo->philo_num % 2)
	{
		pthread_mutex_unlock(&philo->main->fork[philo->l_fork]);
		philo_print(philo, "return fork");
		pthread_mutex_unlock(&philo->main->fork[philo->r_fork]);
		philo_print(philo, "return fork");
	}
	else
	{
		pthread_mutex_unlock(&philo->main->fork[philo->r_fork]);
		philo_print(philo, "return fork");
		pthread_mutex_unlock(&philo->main->fork[philo->l_fork]);
		philo_print(philo, "return fork");
	}
}

void	sleeping(t_philo *philo)
{
	int	i;

	i = -1;
	philo_print(philo, "sleeping");
	usleep(1000 * philo->main->arg_info.time_to_sleep);
	// while (!philo->main->stop && ++i < philo->main->arg_info.time_to_sleep)
	// 	usleep(1000);	
}