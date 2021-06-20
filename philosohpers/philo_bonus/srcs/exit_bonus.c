/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 23:05:50 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 00:47:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void    exit_process(t_main *main)
{
    free(main->philo);
    main->stop = 1;
    sem_post(main->done);
    sem_post(main->sem_stop);
    sem_close(main->text);
    sem_unlink("text");
    sem_close(main->fork);
    sem_unlink("fork");
    sem_close(main->sem_stop);
    sem_unlink("stop");
    sem_close(main->done);
    sem_unlink("done");
}