/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:58:06 by skim              #+#    #+#             */
/*   Updated: 2021/06/15 22:27:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->philo_num != philo->main->num_of_philo - 1)\
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
	philo_print(philo, "eating");
	usleep(philo->main->arg_info.time_to_eat * 1000);
	philo->count_eat++;
}

