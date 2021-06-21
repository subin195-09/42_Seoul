/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:39:17 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 15:59:48 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_philo(t_main *main)
{
	int	i;

	main->philo = malloc(sizeof(t_philo) * main->arg_info.num_of_philo);
	main->fork = malloc(sizeof(pthread_mutex_t) * main->arg_info.num_of_philo);
	if (!main->philo || !main->fork)
		return (-1);
	if (pthread_mutex_init(&(main->text), NULL))
		return (-1);
	main->stop = 0;
	main->done_philo = 0;
	i = -1;
	while (++i < main->arg_info.num_of_philo)
	{
		if (pthread_mutex_init(&(main->fork[i]), NULL))
			return (-1);
		if (pthread_mutex_init(&(main->philo[i].mutex_eat), NULL))
			return (-1);
		main->philo[i].main = main;
		main->philo[i].philo_num = i;
		main->philo[i].count_eat = 0;
		main->philo[i].l_fork = i;
		main->philo[i].r_fork = (i + 1) % main->arg_info.num_of_philo;
	}
	return (0);
}

int		check_info(t_arginfo *info)
{
	if (info->num_of_philo < 0 || info->num_of_philo >= 200)
		return (ft_putendl_fd("Error : num of Philoshper", 2));
	else if (info->time_to_die < 60)
		return (ft_putendl_fd("Error : time to Die", 2));
	else if (info->time_to_eat < 60)
		return (ft_putendl_fd("Error : time to Eat", 2));
	else if (info->time_to_sleep < 60)
		return (ft_putendl_fd("Error : time to Sleep", 2));
	return (1);
}

void	get_info(t_arginfo *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		info->num_must_eat = -1;
	else
		info->num_must_eat = ft_atoi(av[5]);
}

int		main(int ac, char *av[])
{
	t_main		main;

	memset(&main, 0, sizeof(t_main));
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Error : arg", 2));
	get_info(&main.arg_info, ac, av);
	if (check_info(&main.arg_info) < 0)
		return (-1);
	if (init_philo(&main) < 0)
		return (ft_putendl_fd("Error : init_philo", 2));
	philo(&main);
	exit_thread(&main);
	return (0);
}
