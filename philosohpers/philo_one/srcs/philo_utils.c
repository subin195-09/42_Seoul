/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:41:45 by skim              #+#    #+#             */
/*   Updated: 2021/06/03 21:45:08 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

long	get_time(void)
{
	struct timeval	time;
	long			rt;

	gettimeofday(&time, NULL);
	rt = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (rt);
}

void	mutext_print(t_philo *ph, char *s, int ph_num, int died)
{
	long	diff_time;

	pthread_mutex_lock(&ph->info->text);
	diff_time = get_time() - ph->info->start_time;
	printf("%ldms\tPhilosopher(%d) : %s", diff_time, ph_num + 1, s);
	if (died == 1)
		return ;
	pthread_mutex_unlock(&ph->info->text);
}
