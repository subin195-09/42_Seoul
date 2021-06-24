/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_done_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 19:41:32 by skim              #+#    #+#             */
/*   Updated: 2021/06/24 14:15:52 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*is_done(void *arg)
{
	t_main	*main;
	int		count;

	count = 0;
	main = (t_main *)arg;
	while (1)
	{
		sem_wait(main->done);
		if (main->stop)
			break ;
		count++;
		if (count == main->arg_info.num_of_philo)
			break ;
	}
	if (!main->stop)
	{
		sem_post(main->sem_stop);
		philo_print_done(main);
		main->stop = 1;
	}
	return (0);
}

int		done_check(t_main *main)
{
	pthread_t	done_th;

	if (pthread_create(&done_th, 0, is_done, (void *)main))
		return (-1);
	pthread_detach(done_th);
	return (1);
}
