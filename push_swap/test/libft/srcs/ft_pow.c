/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:50:02 by skim              #+#    #+#             */
/*   Updated: 2020/11/05 21:12:05 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_ull		ft_pow(unsigned long long num, int exp)
{
	t_ull	temp;
	int		n;

	n = 0;
	temp = num;
	if (exp == 0)
		return (1);
	while (++n < exp)
		num *= temp;
	return (num);
}
