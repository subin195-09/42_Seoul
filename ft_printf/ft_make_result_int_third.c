/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int_third.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:24:50 by skim              #+#    #+#             */
/*   Updated: 2020/10/29 01:06:45 by skim             ###   ########.fr       */
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

int		check_space(char *result, int len, int sign, t_info info)
{
	if (len != info.width && info.space && !sign)
		return (write(1, " ", 1));
	else if (len == info.width && info.space && ft_isdigit(result[0]))
		return (write(1, " ", 1));
	else
		return (0);
}
