/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:35:11 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:26:10 by skim             ###   ########.fr       */
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
	pthread_mutex_t		mutex_eat;
	struct s_main		*main;
	int					philo_num;
	int					count_eat;
	int					l_fork;
	int					r_fork;
	int					philo_time;
}						t_philo;

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
	int					stop;
	int					done_philo;
	int					start_time;
}						t_main;

int						ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *str);
int						ft_atoi(const char *str);
void					ft_putnbr_fd(int n, int fd);

int						philo(t_main *main);

void					eat(t_philo *philo);
void					get_fork(t_philo *philo);
void					return_fork(t_philo *philo);
void					sleeping(t_philo *philo);

int						get_time(void);
void					philo_print(t_philo *philo, char *s, int type);

void					exit_thread(t_main *main);

#endif
