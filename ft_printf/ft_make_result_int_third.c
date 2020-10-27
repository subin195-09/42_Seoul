/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int_third.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:24:50 by skim              #+#    #+#             */
/*   Updated: 2020/10/28 04:39:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_max(int a, int b, int c)
{
	int max;

	max = a > b ? a : b;
	max = max > c ? max : c;
	return (max);
}

int		check_space(int len, int count, int sign, t_info info)
{
	if ((len == count || len == info.precision + sign) && info.space && !sign)
		return (write(1, " ", 1));
	else
		return (0);
}
