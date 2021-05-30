#include "philo_one.h"

int		ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		num = num * 10 + str[i++] - '0';
	return ((int)(sign * num));
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int     ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return (-1);
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
    if (fd == 2)
        return (-1);
    else
        return (1);
}


void    get_info(s_info *info, int ac, char *av[])
{
    info->num_of_philo = ft_atoi(av[1]);
    info->time_to_die = ft_atoi(av[2]);
    info->time_to_eat = ft_atoi(av[3]);
    info->time_to_sleep = ft_atoi(av[4]);
    if (ac == 5)
        info->num_must_eat = 1;
    else
        info->num_must_eat = ft_atoi(av[5]);
}

int     check_info(s_info *info)
{
    if (info->num_of_philo < 2)
       return (ft_putendl_fd("Error : num of Philoshper", 2));
    else if (info->time_to_die < 60)
        return (ft_putendl_fd("Error : time to Die", 2));
    else if (info->time_to_eat < 20)
        return (ft_putendl_fd("Error : time to Eat", 2));
    else if (info->time_to_sleep < 60)
        return (ft_putendl_fd("Error : time to Sleep", 2));
    else if (info->num_must_eat < 0)
        return (ft_putendl_fd("Error : time must Die", 2));
    return (1);
}

int     main(int ac, char *av[])
{
    s_info  info;

    memset(&info, 0, sizeof(info));
    if (ac != 5 && ac != 6)
        return (ft_putendl_fd("Error : arg", 2));
    get_info(&info, ac, av);
    if (check_info(&info) < 0)
        return (-1);
    return (0);
}