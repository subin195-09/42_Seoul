/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:04:48 by skim              #+#    #+#             */
/*   Updated: 2021/06/20 22:31:02 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		routine(void *arg)
{
	pthread_t	th;
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->philo_time = get_time();
	if (pthread_create(&th, 0, monitor, philo))
		exit(ft_putendl_fd("Error : process", 2));
	pthread_detach(th);
	while (1)
	{
		pick_up_fork(philo);
		eat(philo);
		philo->count_eat++;
			
	}
}

void	*is_died(void *arg)
{
	t_main	*main;

	main = (t_main *)arg;
	sem_wait(main->died);
	main->stop = 1;
	return (0);
}

void	*is_done(void *arg)
{
	t_main	*main;
	int		count;

	count = 0;
	main = (t_main *)arg;
	while (1)
	{
		sem_wait(main->done);
		count++;
		if (count == main->arg_info.num_of_philo)
			break ;
	}
	main->stop = 1;
	return (0);
}

int     philo_bonus(t_main *main)
{
	int         i;
	pthread_t   died_th;
	pthread_t   done_th;
	
	main->start_time = get_time();
	main->stop = 0;
	if (pthread_create(&died_th, 0, is_died, (void *)main))
		return (ft_putendl_fd("Error : thread", 2));
	pthread_detach(died_th);
	if (main->arg_info.num_must_eat > 0)
	{
		if (pthread_create(&done_th, 0, is_done, (void *)main))
			return (ft_putendl_fd("Error : thread", 2));
		pthread_detach(done_th);
	}
	i = -1;
	while (++i < main->arg_info.num_of_philo)
	{
		main->philo[i].philo_time = get_time();
		main->philo[i].pid = fork();
		if (main->philo[i].pid < 0)
			return (ft_putendl_fd("Error : process", 2));
		else if (main->philo[i].pid == 0)
			routine(&(main->philo[i]);
	}
	while (!main->stop)
		usleep(100);
	return (0);
}