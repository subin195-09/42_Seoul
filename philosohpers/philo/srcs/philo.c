/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:52:08 by skim              #+#    #+#             */
/*   Updated: 2021/06/24 14:34:13 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		how_many_eat(t_philo *philo)
{
	if (philo->count_eat == philo->main->arg_info.num_must_eat)
		philo->main->done_philo++;
	if (philo->main->done_philo == philo->main->arg_info.num_of_philo)
	{
		philo_print(philo, "\033[32mdone", 1);
		return (-1);
	}
	return (1);
}

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->main->stop)
	{
		pthread_mutex_lock(&(philo->mutex_eat));
		if (get_time() - philo->philo_time >= philo->main->arg_info.time_to_die)
		{
			philo_print(philo, "\e[91mdied", 1);
			pthread_mutex_unlock(&(philo->mutex_eat));
			return (0);
		}
		pthread_mutex_unlock(&(philo->mutex_eat));
		usleep(100);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (!(philo->philo_num % 2))
		usleep(1000 * philo->main->arg_info.time_to_eat);
	while (!philo->main->stop)
	{
		if (philo->main->stop)
			break ;
		get_fork(philo);
		eat(philo);
		return_fork(philo);
		if (philo->main->arg_info.num_must_eat != -1 && how_many_eat(philo) < 0)
			break ;
		if (philo->main->stop)
			break ;
		sleeping(philo);
		if (philo->main->stop)
			break ;
		philo_print(philo, "thinking", 0);
	}
	return (0);
}

int		philo(t_main *main)
{
	pthread_t	th;
	int			i;

	i = -1;
	main->start_time = get_time();
	while (++i < main->arg_info.num_of_philo)
	{
		main->philo[i].philo_time = get_time();
		if (pthread_create(&th, 0, routine, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : routine", 2));
		pthread_detach(th);
		if (pthread_create(&(main->philo[i].philo_thr), \
		0, monitor, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : monitor", 2));
	}
	i = -1;
	while (++i < main->arg_info.num_of_philo)
		pthread_join(main->philo[i].philo_thr, 0);
	return (1);
}
