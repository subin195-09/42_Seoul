/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:07:04 by skim              #+#    #+#             */
/*   Updated: 2020/10/02 15:40:34 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	temp;
	char		sign;

	temp = n;
	temp = (temp >= 0) ? temp : -temp;
	if (n < 0)
		write(1, "-", 1);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (temp > 0)
	{
		write(fd, (temp % 10) + '0', 1);
		temp /= 10;
	}

}
