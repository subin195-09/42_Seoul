/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:58:06 by skim              #+#    #+#             */
/*   Updated: 2021/06/15 21:32:24 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->philo_num)
	pthread_mutex_lock(&philo->main->fork[philo->l_fork]);
	philo->main->fork_flag[philo->l_fork] = 1;
	philo_print(philo, "pick_up fork");
	pthread_mutex_lock(&philo->main->fork[philo->r_fork]);
	philo->main->fork_flag[philo->r_fork] = 1;
	philo_print(philo, "pick_up fork");
}
