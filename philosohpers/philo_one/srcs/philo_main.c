/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:55 by skim              #+#    #+#             */
/*   Updated: 2021/06/01 06:52:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    mutext_print(t_philo *ph, char *s, int ph_num)
{
	pthread_mutex_lock(&ph->info->text);
	printf("%d : %s", ph_num, s);
	pthread_mutex_unlock(&ph->info->text);
}

void    pick_up_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->info->fork[ph->p_num]);
	mutext_print(ph, "pick up fork\n", ph->p_num);
	pthread_mutex_lock(&ph->info->fork[(ph->p_num + 1) % ph->info->num_of_philo]);
	mutext_print(ph, "pick up fork\n", ph->p_num);
}

void    eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->p_mu_eat);
	mutext_print(ph, "eating\n", ph->p_num);
	usleep(ph->info->time_to_eat * 1000);
	ph->count_eat++;
	pthread_mutex_unlock(&ph->p_mu_eat);
}

void    return_fork(t_philo *ph)
{
	pthread_mutex_unlock(&ph->info->fork[ph->p_num]);
	mutext_print(ph, "return fork\n", ph->p_num);
	pthread_mutex_unlock(&ph->info->fork[(ph->p_num + 1) % ph->info->num_of_philo]);
	mutext_print(ph, "return fork\n", ph->p_num);
}

void    sleeping(t_philo *ph)
{
	mutext_print(ph, "sleeping\n", ph->p_num);
	usleep(ph->info->time_to_sleep * 1000);
}

int     check_eat_count(t_philo *ph)
{
	if (ph->count_eat == ph->info->num_must_eat)
		ph->info->done_eat++;
	if (ph->info->done_eat == ph->info->num_of_philo)
	{
		mutext_print(ph, "done eat all\n", ph->p_num);
		ph->info->stop = 1;
		return (-1);
	}
	return (1);
}

void    *ph_start(void  *arg)
{
	t_philo *philo;
	int     i;

	philo = (t_philo *)arg;
	i = -1;
	while (++i < philo->info->num_must_eat)
	{
		pick_up_fork(philo);
		eat(philo);
		return_fork(philo);
		if (check_eat_count(philo) < 0)
			break ;
		sleeping(philo);
		mutext_print(philo, "thinking\n", philo->p_num);
	}
	pthread_mutex_unlock(&philo->info->fork[philo->p_num]);
	pthread_mutex_unlock(&philo->info->fork[(philo->p_num + 1) % philo->info->num_of_philo]);
	pthread_mutex_unlock(&philo->info->text);
	return (0);
}

void    *check_die(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	usleep(1000 * 1000);
	return (0);
}

int     philo_main(t_info *info)
{
	pthread_t   thread;
	int         i;

	i = -1;
	while (++i < info->num_of_philo)
	{
		if (pthread_create(&thread, NULL, ph_start, (void *)&(info->ph[i])))
			return (ft_putendl_fd("Error : ph_start", 2));
		pthread_detach(thread);
		if (pthread_create(&(info->ph[i].p_th), NULL, check_die, (void *)&(info->ph[i])))
			return (ft_putendl_fd("Error : ph_start", 2));
		usleep(1000);
	}
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->ph[i].p_th, NULL);
	i = -1;
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&(info->ph[i].p_mu_eat));
	return (0);
}