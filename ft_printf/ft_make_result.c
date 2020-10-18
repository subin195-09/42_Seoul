/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/18 16:18:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result(const char **format, s_info info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'd' || **format == 'i')
		count_bytes = make_result_int(info, var);
	(*format)++;
	return (count_bytes);
}
