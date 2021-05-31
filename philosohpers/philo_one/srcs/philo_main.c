/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 21:53:55 by skim              #+#    #+#             */
/*   Updated: 2021/05/31 23:30:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void    init_philo(s_philo *ph)
{
    ph->count_eat = 0;
}

void    *ph_start(void  *arg)
{
    s_info *ph;
    int     i;

    ph = (s_info *)arg;
    i = -1;
    while (++i < )
}

int     philo_main(s_info *info)
{
    s_philo ph[info->num_of_philo];
    int     i;

    init_philo(&ph);
    i = -1;
    while (++i < info->num_of_philo)
    {
        info->ph = ph[i];
        if (pthread_create(&(ph[i].p_th), NULL, ph_start, info))
            return (ft_putendl_fd("Error : create thread", 2));
    }
    i = -1;
    while (++i < info->num_of_philo)
        pthread_join(ph[i], NULL);
    i = -1;
    while (++i < info->num_of_philo)
        pthread_mutex_destroy(&(ph.p_mu));
}