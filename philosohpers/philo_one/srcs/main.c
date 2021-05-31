/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:21 by skim              #+#    #+#             */
/*   Updated: 2021/05/31 21:54:45 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    get_info(s_info *info, int ac, char *av[])
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

int     check_info(s_info *info)
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

int     main(int ac, char *av[])
{
    s_info  info;

    memset(&info, 0, sizeof(info));
    if (ac != 5 && ac != 6)
        return (ft_putendl_fd("Error : arg", 2));
    get_info(&info, ac, av);
    if (check_info(&info) < 0)
        return (-1);
    philo_main(&info);
    return (0);
}