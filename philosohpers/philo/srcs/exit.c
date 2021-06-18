/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:09:13 by skim              #+#    #+#             */
/*   Updated: 2021/06/18 16:29:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_thread(t_main *main)
{
	int	i;
	
	usleep(1000);
	i = -1;
	pthread_mutex_destroy(&main->text);
	while (++i < main->arg_info.num_of_philo)
		pthread_mutex_destroy(&main->fork[i]);
	free(main->philo);
	free(main->fork);
}
