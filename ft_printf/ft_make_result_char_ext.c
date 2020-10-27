/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_char_ext.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:25:01 by skim              #+#    #+#             */
/*   Updated: 2020/10/27 17:37:09 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result_char_extend(t_info info, va_list var)
{
	int num;
	int count_bytes;

	count_bytes = 0;
	num = va_arg(var, int);
	if (info.width > 1)
	{
		if (info.left)
			count_bytes += write_result_ext(num);
		while (info.width--)
			count_bytes += write(1, " ", 1);
		if (!info.left)
			count_bytes += write_result_ext(num);
	}
	else
		count_bytes += write_result_ext(num);
	return (count_bytes);
}
