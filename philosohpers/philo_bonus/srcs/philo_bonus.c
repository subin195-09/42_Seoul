/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 21:04:48 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 01:03:25 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*other_monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	sem_wait(philo->main->sem_stop);
	philo->philo_died = 1;
	sem_post(philo->main->sem_stop);
	exit(0);
	return (0);
}

void	*monitor(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time() - philo->philo_time >= philo->main->arg_info.time_to_die)
		{
			philo_print(philo, "\e[91mdied", 1);
			sem_post(philo->main->sem_stop);
			exit(0);
		}
	}
	return (0);
}

int		routine(void *arg)
{
	pthread_t	th;
	t_philo		*philo;

	philo = (t_philo *)arg;
	philo->philo_time = get_time();
	if (pthread_create(&th, 0, monitor, philo))
		exit(ft_putendl_fd("Error : process", 2));
	pthread_detach(th);
	if (pthread_create(&th, 0, other_monitor, philo))
		exit(ft_putendl_fd("Error : process", 2));
	pthread_detach(th);
	while (1)
	{
		get_fork(philo);
		eat(philo);
		return_fork(philo);
		if (philo->main->arg_info.num_must_eat > 0 &&\
		philo->count_eat == philo->main->arg_info.num_must_eat)
			sem_post(philo->main->done);
		sleeping(philo);
		philo_print(philo, "thinking", 0);
	}
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
		if (main->stop)
			break ;
		count++;
		if (count == main->arg_info.num_of_philo)
			break ;
	}
	if (!main->stop)
	{
		sem_post(main->sem_stop);
		philo_print_done(main);
		main->stop = 1;
	}
	return (0);
}

int     philo_bonus(t_main *main)
{
	int         i;
	pthread_t   done_th;
	int			status;
	
	main->start_time = get_time();
	main->stop = 0;
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
		{
			routine(&(main->philo[i]));
			return (0);
		}
	}
	i = -1;
	while (++i < main->arg_info.num_of_philo)
		waitpid(main->philo[i].pid, &status, 0);
	return (0);
}