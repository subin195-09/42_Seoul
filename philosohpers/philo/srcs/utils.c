/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 18:46:13 by skim              #+#    #+#             */
/*   Updated: 2021/06/21 19:26:35 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_putendl_fd(char *s, int fd)
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

void	write_num(long long temp, int fd)
{
	char	temp_write;

	if (temp == 0)
		return ;
	else
	{
		write_num(temp / 10, fd);
		temp_write = (temp % 10) + '0';
		write(fd, &temp_write, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	temp;

	temp = n;
	temp = (temp > 0) ? temp : -temp;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	write_num(temp, fd);
}
