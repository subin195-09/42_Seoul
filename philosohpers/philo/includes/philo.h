/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:35:11 by skim              #+#    #+#             */
/*   Updated: 2021/06/15 21:02:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct			s_philo
{
	pthread_t			philo_thr;
	pthread_mutex_t		eat_mutex;
	struct s_main		*main;
	int					philo_num;
	int					count_eat;
	int					l_fork;
	int					r_fork;
	long				philo_time;
}				 		t_philo;

typedef struct			s_arginfo
{
	int					num_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					num_must_eat;
}						t_arginfo;

typedef	struct			s_main
{
	struct s_arginfo	arg_info;
	struct s_philo		*philo;
	pthread_mutex_t		*fork;
	pthread_mutex_t		text;
	int					*fork_flag;
	int					stop;
	int					done_philo;
	long				start_time;
}						t_main;

int						ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *str);
int						ft_atoi(const char *str);

#endif
