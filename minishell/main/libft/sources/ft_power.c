/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:01:45 by spark             #+#    #+#             */
/*   Updated: 2020/11/09 15:54:44 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_power(int time)
{
	unsigned long long		rt;
	int						i;

	rt = 1;
	i = 0;
	while (i < time)
	{
		rt *= 10;
		i++;
	}
	return (rt);
}
