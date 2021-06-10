/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:40:45 by skim              #+#    #+#             */
/*   Updated: 2021/06/10 17:02:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	pick_up_fork(t_philo *ph)
{
	sem_wait(ph->info->fork);
	sema_print(ph, "pick up fork\n", ph->p_num, 0);
	sem_wait(ph->info->fork);
	sema_print(ph, "pick up fork\n", ph->p_num, 0);
}

void	eat(t_philo *ph)
{
	sem_wait(ph->p_se_eat);
	sema_print(ph, "eating\n", ph->p_num, 0);
	usleep(ph->info->time_to_eat * 1000);
	ph->count_eat++;
	sem_post(ph->p_se_eat);
}

void	return_fork(t_philo *ph)
{
	sem_post(ph->info->fork);
	sema_print(ph, "return fork\n", ph->p_num, 0);
	sem_post(ph->info->fork);
	sema_print(ph, "return fork\n", ph->p_num, 0);
}

void	sleeping(t_philo *ph)
{
	sema_print(ph, "sleeping\n", ph->p_num, 0);
	usleep(ph->info->time_to_sleep * 1000);
}
