/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 21:38:41 by skim              #+#    #+#             */
/*   Updated: 2021/06/05 21:51:45 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct		s_philo{
	pthread_t		p_th;
	pthread_mutex_t	p_mu_eat;
	struct s_info	*info;
	int				p_num;
	int				count_eat;
	int				l_fork;
	int				r_fork;
	long			ph_time;
}					t_philo;

typedef struct		s_info{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				stop;
	int				done_eat;
	long			start_time;
	struct s_philo	*ph;
	pthread_mutex_t	*fork;
	pthread_mutex_t	text;
}					t_info;

int					philo_main(t_info *info);
void				pick_up_fork(t_philo *ph);
void				eat(t_philo *ph);
void				return_fork(t_philo *ph);
void				sleeping(t_philo *ph);

long				get_time(void);
void				mutext_print(t_philo *ph, char *s, int ph_num, int died);

int					ft_putendl_fd(char *s, int fd);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *str);

#endif
