/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:55 by skim              #+#    #+#             */
/*   Updated: 2021/06/08 17:46:57 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int		check_eat_count(t_philo *ph)
{
	if (ph->info->num_must_eat > 0 && ph->count_eat == ph->info->num_must_eat)
		ph->info->done_eat++;
	if (ph->info->num_must_eat > 0 && \
	ph->info->done_eat == ph->info->num_of_philo)
	{
		ph->info->stop = 1;
		sema_print(ph, "\e[91mdone\n", ph->p_num, 1);
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
		sem_wait(philo->p_se_eat);
		if (!philo->info->stop && get_time() - \
		philo->ph_time > philo->info->time_to_die)
		{
			philo->info->stop = 1;
			sema_print(philo, "\e[91mdied\n", philo->p_num, 1);
			sem_post(philo->p_se_eat);
			return (0);
		}
		sem_post(philo->p_se_eat);
		usleep(100); // 이건 왜...???
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
		sema_print(philo, "thinking\n", philo->p_num, 0);
	}
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	sem_post(philo->p_se_eat);
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
		pthread_detach(thread);
		if (pthread_create(&(info->ph[i].p_th), NULL, \
		check_die, (void *)&(info->ph[i])))
			return (ft_putendl_fd("Error : ph_start", 2));
		usleep(1000); // usleep 이 필요한 이유가 뭐어지ㅣㅣ....????
	}
	i = -1;
	while (++i < info->num_of_philo)
		pthread_join(info->ph[i].p_th, NULL);
	return (0);
}
