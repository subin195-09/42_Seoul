#ifndef PHILO_ONE_H
# define PHILO_ONE_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct  t_info{
    int     num_of_philo;
    int     time_to_die;
    int     time_to_eat;
    int     time_to_sleep;
    int     num_must_eat;
}               s_info;

#endif