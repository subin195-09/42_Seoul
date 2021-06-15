/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:58:06 by skim              #+#    #+#             */
/*   Updated: 2021/06/15 21:15:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->main->fork_flag[philo->l_fork] * philo->main->fork_flag[philo->r_fork])
	{
		pthread_mutex_lock(&philo->main->fork[philo->l_fork]);
		philo->main->fork_flag[philo->l_fork] = 1;

		pthread_mutex_lock(&philo->main->fork[philo->r_fork]);
		philo->main->fork_flag[philo->r_fork] = 1;
	}
}
