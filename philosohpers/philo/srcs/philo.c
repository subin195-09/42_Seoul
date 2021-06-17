/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:52:08 by skim              #+#    #+#             */
/*   Updated: 2021/06/17 17:53:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->main->stop)
	{
		if (!philo->main->stop && \
		get_time() - philo->philo_time > philo->main->arg_info.time_to_die)
		{
			philo->main->stop = 1;
			philo_print(philo, "\e[91mdied\n");
		}
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (!philo->main->stop)
	{
		get_fork(philo);
		if (philo->main->stop)
			break;
		eat(philo);
		if (philo->main->stop)
			break;
		return_fork(philo);
		if (philo->main->stop)
			break;
		sleeping(philo);
		if (philo->main->stop)
			break;
		philo_print(philo, "thinking");
	}
	i = -1;
	while (++i < philo->main->arg_info.num_of_philo)
		pthread_mutex_unlock(&philo->main->fork[i]);
	pthread_mutex_unlock(&philo->main->text);
}

int		philo(t_main *main)
{
	pthread_t	th;
	int			i;

	i = -1;
	main->start_time = get_time();
	while (++i < main->arg_info.num_of_philo)
	{
		main->philo[i]->philo_time = get_time();
		if (pthread_create(&th, 0, routine, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : routine", 2));
		if (pthread_create(&(main->philo[i].philo_thr), \
		0, monitor, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : monitor", 2));
	}
	i = -1;
	while (++i < main->arg_info.num_of_philo)
		pthread_join(main->philo[i].philo_thr, 0);
	return (1);
}
