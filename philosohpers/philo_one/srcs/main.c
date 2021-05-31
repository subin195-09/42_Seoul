/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:21 by skim              #+#    #+#             */
/*   Updated: 2021/06/01 06:41:35 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		init_philo(t_info *info)
{
	int	i;

	i = -1;
	info->stop = 0;
	info->done_eat = 0;
	info->ph = malloc(sizeof(t_info) * info->num_of_philo);
	info->fork = malloc(sizeof(pthread_mutex_t) * info->num_of_philo);
	if (!info->ph || !info->fork)
		return (-1);
	if (pthread_mutex_init(&(info->text), NULL))
		return (-1);
	while (++i < info->num_of_philo)
	{
		if (pthread_mutex_init(&(info->ph[i].p_mu_eat), NULL))
			return (-1);
		if (pthread_mutex_init(&(info->fork[i]), NULL))
			return (-1);
		info->ph[i].count_eat = 0;
		info->ph[i].p_num = i;
		info->ph[i].l_fork = i;
		info->ph[i].r_fork = (i + 1) % info->num_of_philo;
		info->ph[i].info = info;
	}
	return (0);
}

int     check_info(t_info *info)
{
	if (info->num_of_philo < 2)
	   return (ft_putendl_fd("Error : num of Philoshper", 2));
	else if (info->time_to_die < 60)
		return (ft_putendl_fd("Error : time to Die", 2));
	else if (info->time_to_eat < 20)
		return (ft_putendl_fd("Error : time to Eat", 2));
	else if (info->time_to_sleep < 60)
		return (ft_putendl_fd("Error : time to Sleep", 2));
	else if (info->num_must_eat < 0)
		return (ft_putendl_fd("Error : time must Die", 2));
	return (1);
}

void    get_info(t_info *info, int ac, char *av[])
{
	info->num_of_philo = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (ac == 5)
		info->num_must_eat = 1;
	else
		info->num_must_eat = ft_atoi(av[5]);
}

int     main(int ac, char *av[])
{
	t_info  info;

	memset(&info, 0, sizeof(t_info));
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Error : arg", 2));
	get_info(&info, ac, av);
	if (check_info(&info) < 0)
		return (-1);
	if (init_philo(&info) < 0)
		return (ft_putendl_fd("Error : init_philo", 2));
	philo_main(&info);
	free(info.ph);
	return (0);
}