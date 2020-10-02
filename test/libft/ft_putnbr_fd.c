/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:07:04 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 00:39:07 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void 	write_num(long long temp, int fd)
{
	if (temp == 0)
		return ;
	else
	{
		write_num(temp / 10, fd);
		char temp_write = (temp % 10) + '0';
		write(fd, &temp_write, 1);
	}
}

void			ft_putnbr_fd(int n, int fd)
{
	long long	temp;

	temp = n;
	temp = (temp >= 0) ? temp : -temp;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(1, "-", 1);
	write_num(temp, fd);
}
