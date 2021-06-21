/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 21:41:45 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:28:41 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int		get_time(void)
{
	struct timeval	time;
	int				rt;

	gettimeofday(&time, NULL);
	rt = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (rt);
}

void	philo_print(t_philo *philo, char *s, int type)
{
	int	diff_time;

	sem_wait(philo->main->text);
	if (philo->philo_died)
	{
		sem_post(philo->main->text);
		return ;
	}
	diff_time = get_time() - philo->main->start_time;
	if (type == 2)
		printf("%dms\tPhilosopher(all) : %s\n", diff_time, s);
	else
		printf("%dms\tPhilosopher(%d) : %s\n", \
		diff_time, philo->philo_num + 1, s);
	if (type)
		philo->philo_died = 1;
	sem_post(philo->main->text);
}

void	philo_print_done(t_main *main)
{
	int	diff_time;

	sem_wait(main->text);
	diff_time = get_time() - main->start_time;
	printf("%dms\tPhilosopher(all) : \033[32mdone\n", diff_time);
	sem_post(main->text);
}

char	*make_sem_name(t_philo *philo)
{
	char	*name;

	name = ft_strdup("philo");
	return (ft_strjoin(name, ft_itoa(philo->philo_num)));
}
