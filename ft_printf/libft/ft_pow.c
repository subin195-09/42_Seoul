/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 17:50:02 by skim              #+#    #+#             */
/*   Updated: 2020/11/02 18:02:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_pow(unsigned long long num, int exp)
{
	int	n;

	n = 0;
	if (exp == 0)
		return (1);
	while (++n < exp)
		num *= num;
	return (num);
}
