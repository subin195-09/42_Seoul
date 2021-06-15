/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:52:08 by skim              #+#    #+#             */
/*   Updated: 2021/06/15 21:10:00 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
}

void	*routine(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	philo->philo_time = get_time();
	while (!philo->main->stop)
	{
		get_fork(philo);
		eat(philo);
		return_fork(philo);
		sleeping(philo);
		thinking(philo);
	}
	i = -1;
	while (++i < philo->main->arg_info.num_of_philo)
		pthread_mutex_unlock(&philo->main->fork[i]);
	pthread_mutex_unlock(&philo->main->text);
}

void	philo(t_main *main)
{
	pthread_t	th;
	int			i;

	i = -1;
	main->start_time = get_time();
	while (++i < main->arg_info.num_of_philo)
	{
		if (pthread_create(&th, 0, routine, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : routine", 2));
		if (pthread_creatre(&(main->philo[i].philo_thr), \
		0, monitor, (void *)&(main->philo[i])))
			return (ft_putendl_fd("Error : monitor", 2));
	}
	i = -1;
	while (++i < main->arg_info.num_of_philo)
		pthread_join(main->philo[i].philo_thr, 0);
}
