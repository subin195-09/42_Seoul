/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:50:02 by skim              #+#    #+#             */
/*   Updated: 2020/11/05 16:01:03 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_pow(unsigned long long num, int exp)
{
	double	temp;
	int		n;

	n = 0;
	temp = num;
	if (exp == 0)
		return (1);
	if (exp < 0)
	{
		while (++n < exp)
			num /= temp;
	}
	else
	{
		while (++n < exp)
			num *= temp;
	}
	return (num);
}
