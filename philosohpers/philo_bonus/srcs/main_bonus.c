/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:21 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:33:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	init_each_philo(t_main *main)
{
	int	i;

	i = -1;
	while (++i < main->arg_info.num_of_philo)
	{
		main->philo[i].tmp_name = make_sem_name(&main->philo[i]);
		sem_unlink(main->philo[i].tmp_name);
		main->philo[i].sem_eat = \
		sem_open(main->philo[i].tmp_name, O_CREAT, 0644, 1);
		main->philo[i].main = main;
		main->philo[i].philo_died = 0;
		main->philo[i].philo_num = i;
		main->philo[i].count_eat = 0;
	}
}

int		init_philo(t_main *main)
{
	main->philo = malloc(sizeof(t_philo) * main->arg_info.num_of_philo);
	if (!main->philo)
		return (-1);
	sem_unlink("text");
	sem_unlink("fork");
	sem_unlink("stop");
	sem_unlink("done");
	main->text = sem_open("text", O_CREAT, 0644, 1);
	main->fork = sem_open("fork", O_CREAT, 0644, main->arg_info.num_of_philo);
	main->sem_stop = sem_open("stop", O_CREAT, 0644, 0);
	main->done = sem_open("done", O_CREAT, 0644, 1);
	main->stop = 0;
	main->done_philo = 0;
	init_each_philo(main);
	return (0);
}

int		check_info(t_arginfo *info)
{
	if (info->num_of_philo < 2)
		return (ft_putendl_fd("Error : num of Philoshper", 2));
	else if (info->time_to_die < 60)
		return (ft_putendl_fd("Error : time to Die", 2));
	else if (info->time_to_eat < 20)
		return (ft_putendl_fd("Error : time to Eat", 2));
	else if (info->time_to_sleep < 60)
		return (ft_putendl_fd("Error : time to Sleep", 2));
	return (1);
}

void	get_main(t_arginfo *info, int ac, char *av[])
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
	t_main	main;

	memset(&main, 0, sizeof(t_main));
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Error : arg", 2));
	get_main(&main.arg_info, ac, av);
	if (check_info(&main.arg_info) < 0)
		return (-1);
	if (init_philo(&main) < 0)
		return (ft_putendl_fd("Error : init_philo", 2));
	philo_bonus(&main);
	exit_process(&main);
	return (0);
}
