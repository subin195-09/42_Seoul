/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:40:45 by skim              #+#    #+#             */
/*   Updated: 2021/06/11 20:32:00 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	pick_up_fork(t_philo *ph)
{
	if (ph->p_num % 2)
	{
		pthread_mutex_lock(&ph->info->fork[ph->p_num]);
		mutext_print(ph, "pick up fork\n", ph->p_num, 0);
		pthread_mutex_lock(&ph->info->fork[(ph->p_num + 1)\
		% ph->info->num_of_philo]);
		mutext_print(ph, "pick up fork\n", ph->p_num, 0);
	}
	else
	{
		pthread_mutex_lock(&ph->info->fork[(ph->p_num + 1)\
		% ph->info->num_of_philo]);
		mutext_print(ph, "pick up fork\n", ph->p_num, 0);
		pthread_mutex_lock(&ph->info->fork[ph->p_num]);
		mutext_print(ph, "pick up fork\n", ph->p_num, 0);
	}
}

void	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->p_mu_eat);
	mutext_print(ph, "eating\n", ph->p_num, 0);
	usleep(ph->info->time_to_eat * 1000);
	ph->count_eat++;
	pthread_mutex_unlock(&ph->p_mu_eat);
}

void	return_fork(t_philo *ph)
{
	if (ph->p_num % 2)
	{
		pthread_mutex_unlock(&ph->info->fork[ph->p_num]);
		mutext_print(ph, "return fork\n", ph->p_num, 0);
		pthread_mutex_unlock(&ph->info->fork[(ph->p_num + 1)\
		% ph->info->num_of_philo]);
		mutext_print(ph, "return fork\n", ph->p_num, 0);
	}
	else
	{
		pthread_mutex_unlock(&ph->info->fork[(ph->p_num + 1)\
		% ph->info->num_of_philo]);
		mutext_print(ph, "return fork\n", ph->p_num, 0);
		pthread_mutex_unlock(&ph->info->fork[ph->p_num]);
		mutext_print(ph, "return fork\n", ph->p_num, 0);
	}

}

void	sleeping(t_philo *ph)
{
	mutext_print(ph, "sleeping\n", ph->p_num, 0);
	usleep(ph->info->time_to_sleep * 1000);
}
