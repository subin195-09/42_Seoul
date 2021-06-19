/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 17:01:58 by skim              #+#    #+#             */
/*   Updated: 2021/06/19 21:13:07 by skim             ###   ########.fr       */
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

typedef struct		s_philo{
	pthread_t		p_th;
	sem_t			*p_se_eat;
	struct s_main	*main;
	int				philo_num;
	int				count_eat;
	int				philo_time;
}					t_philo;

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
	sem_t				*died;
	sem_t				*done;
	int					stop;
	int					done_philo;
	int					start_time;
}						t_main;

int						ft_putendl_fd(char *s, int fd);
size_t					ft_strlen(const char *str);
int						ft_atoi(const char *str);
void					ft_putnbr_fd(int n, int fd);

#endif
