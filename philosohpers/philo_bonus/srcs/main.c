/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:21 by skim              #+#    #+#             */
/*   Updated: 2021/06/10 17:02:08 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	finish(t_info *info)
{
	char	*tmp_name;
	int		i;

	free(info->ph);
	// sem_close(info->text);
	// sem_unlink("text"); // 무한이 도는 이유는...?
	sem_close(info->fork);
	sem_unlink("fork");
	i = -1;
	while (++i < info->num_of_philo)
	{
		tmp_name = ft_itoa(i + 1);
		sem_close(info->ph[i].p_se_eat);
		sem_unlink(tmp_name);
		free(tmp_name);
	}
}

int		init_philo(t_info *info)
{
	char	*tmp_name;
	int		i;

	i = -1;
	info->stop = 0;
	info->done_eat = 0;
	info->ph = malloc(sizeof(t_info) * info->num_of_philo);
	if (!info->ph)
		return (-1);
	sem_unlink("text");
	sem_unlink("fork");
	info->text = sem_open("text", O_CREAT, 0644, 1);
	info->fork = sem_open("fork", O_CREAT, 0644, info->num_of_philo);
	while (++i < info->num_of_philo)
	{
		tmp_name = ft_itoa(i + 1);
		sem_unlink(tmp_name);
		info->ph[i].p_se_eat = sem_open(tmp_name, O_CREAT, 0644, 1);
		info->ph[i].count_eat = 0;
		info->ph[i].p_num = i;
		info->ph[i].info = info;
		free(tmp_name);
	}
	return (0);
}

int		check_info(t_info *info)
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

void	get_info(t_info *info, int ac, char *av[])
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
	t_info	info;

	memset(&info, 0, sizeof(t_info));
	if (ac != 5 && ac != 6)
		return (ft_putendl_fd("Error : arg", 2));
	get_info(&info, ac, av);
	if (check_info(&info) < 0)
		return (-1);
	if (init_philo(&info) < 0)
		return (ft_putendl_fd("Error : init_philo", 2));
	philo_main(&info);
	finish(&info);
	return (0);
}
