/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/19 19:31:50 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result(const char **format, t_info info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'd' || **format == 'i')
		count_bytes = make_result_int(info, var);
	if (**format == 'c')
		count_bytes = make_result_char(info, var);
	if (**format == 's')
		count_bytes = make_result_string(info, var);
	(*format)++;
	return (count_bytes);
}
