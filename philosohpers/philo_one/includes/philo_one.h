/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 22:59:46 by skim              #+#    #+#             */
/*   Updated: 2021/05/31 23:29:24 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct  t_philo{
    pthread_t       p_th;
    pthread_mutex_t p_mu;
    int             l_fork;
    int             r_fork;
    int             count_eat;
    int             p_num;
}               s_philo;

typedef struct  t_info{
    int             num_of_philo;
    int             time_to_die;
    int             time_to_eat;
    int             time_to_sleep;
    int             num_must_eat;
    struct t_philo  ph;
}               s_info;

int     philo_main(s_info *info);

int     ft_putendl_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);

#endif