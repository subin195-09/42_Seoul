/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:09:13 by skim              #+#    #+#             */
/*   Updated: 2021/06/19 20:26:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_thread(t_main *main)
{
	int	i;

	usleep(2000);
	i = -1;
	pthread_mutex_destroy(&main->text);
	while (++i < main->arg_info.num_of_philo)
		pthread_mutex_destroy(&main->fork[i]);
	free(main->philo);
	free(main->fork);
}
