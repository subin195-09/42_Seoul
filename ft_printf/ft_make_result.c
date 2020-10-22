/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/22 16:00:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result(const char **format, t_info *info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'c')
		count_bytes = make_result_char(*info, var);
	if (**format == 's')
		count_bytes = make_result_string(*info, var);
	if (**format == 'd' || **format == 'i')
		count_bytes = make_result_int(*info, var);
	if (**format == 'u' || **format == 'x' || **format == 'X')
	{
		info->check_sign = 0;
		count_bytes = make_result_uint(*info, var, **format);
	}
	(*format)++;
	return (count_bytes);
}
