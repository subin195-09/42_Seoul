/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:07:04 by skim              #+#    #+#             */
/*   Updated: 2020/10/02 16:46:47 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	ft_putnbr_fd(int n, int fd)
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

	while (temp > 0)
	{
		char temp_write = (temp % 10) + '0';
		write(fd, &temp_write, 1);
		temp /= 10;
	}

}
