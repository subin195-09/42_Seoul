/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:55 by skim              #+#    #+#             */
/*   Updated: 2021/06/14 14:53:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_eat_count(t_philo *ph)
{
	if (ph->info->num_must_eat > 0 && ph->count_eat == ph->info->num_must_eat)
		ph->info->done_eat++;
	if (ph->info->num_must_eat > 0 && \
	ph->info->done_eat == ph->info->num_of_philo)
	{
		ph->info->stop = 1;
		mutext_print(ph, "\e[91mdone\n", ph->p_num, 1);
		return (-1);
	}
	return (1);
}

void	*check_die(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (!philo->info->stop)
	{
		pthread_mutex_lock(&philo->p_mu_eat);
		if (!philo->info->stop && get_time() - \
		philo->ph_time > philo->info->time_to_die)
		{
			philo->info->stop = 1;
			mutext_print(philo, "\e[91mdied\n", philo->p_num, 1);
			pthread_mutex_unlock(&philo->p_mu_eat);
			return (0);
		}
		pthread_mutex_unlock(&philo->p_mu_eat);
		// usleep(100); // 이건 왜...???
	}
	return (0);
}

void	*ph_routine(void *arg)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)arg;
	i = -1;
	philo->ph_time = get_time();
	while (!philo->info->stop)
	{
		pick_up_fork(philo);
		if (philo->info->stop)
			break ;
		philo->ph_time = get_time();
		eat(philo);
		if (philo->info->stop)
			break ;
		return_fork(philo);
		if (check_eat_count(philo) < 0 || philo->info->stop)
			break ;
		sleeping(philo);
		mutext_print(philo, "thinking\n", philo->p_num, 0);
	}
	pthread_mutex_unlock(&philo->info->fork[philo->p_num]);
	pthread_mutex_unlock(&philo->info->fork[(philo->p_num + 1) % \
	philo->info->num_of_philo]);
	return (0);
}

int		philo_main(t_info *info)
{
	pthread_t	thread;
	int			i;

	i = -1;
	info->start_time = get_time();
	while (++i < info->num_of_philo)
	{
		info->ph[i].ph_time = get_time();
		if (pthread_create(&thread, NULL, ph_routine, (void *)&(info->ph[i])))
			return (ft_putendl_fd("Error : ph_start", 2));
		if (pthread_create(&(info->ph[i].p_th), NULL, \
		check_die, (void *)&(info->ph[i])))
			return (ft_putendl_fd("Error : ph_start", 2));
		usleep(1000); // thread를 생성하는데 시간이 걸리기 때문에
	}
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->ph[i].p_th, NULL);
	i = -1;
	//pthread_mutex_unlock(&info->text);
	while (++i < info->num_of_philo)
		pthread_mutex_destroy(&(info->ph[i].p_mu_eat));
	return (0);
}
