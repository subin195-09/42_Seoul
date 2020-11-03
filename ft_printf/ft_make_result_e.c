/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:11:11 by skim              #+#    #+#             */
/*   Updated: 2020/11/03 21:38:24 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result_e(t_info info, va_list var)
{
	char	*result;
	char	*char_num;
	double	num;
	double	chang_num;
	int		r_num;
	int		exp;

	exp = 0;
	num = va_arg(var, double);
	r_num = num;
	if (r_num == 0)
	{
		while (r_num >= 10)
		{
			r_num *= 10;
			exp--;
		}
	}
	else
	{
		while (r_num >= 10)
		{
			r_num /= 10;
			exp++;
		}
	}
	
}
