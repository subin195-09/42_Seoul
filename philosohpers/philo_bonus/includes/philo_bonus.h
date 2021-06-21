/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:01:58 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:46:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>

typedef struct			s_philo
{
	pid_t				pid;
	sem_t				*sem_eat;
	struct s_main		*main;
	char				*tmp_name;
	int					philo_died;
	int					philo_num;
	int					count_eat;
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
	sem_t				*fork;
	sem_t				*text;
	sem_t				*sem_stop;
	sem_t				*done;
	int					stop;
	int					done_philo;
	int					start_time;
}						t_main;

int						ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *str);
int						ft_atoi(const char *str);
char					*ft_itoa(int n);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strdup(const char *src);

int						philo_bonus(t_main *main);
void					exit_process(t_main *main);
int						done_check(t_main *main);

void					get_fork(t_philo *philo);
void					eat(t_philo *philo);
void					return_fork(t_philo *philo);
void					sleeping(t_philo *philo);

int						get_time(void);
void					philo_print(t_philo *philo, char *s, int type);
void					philo_print_done(t_main *main);
char					*make_sem_name(t_philo *philo);

#endif
