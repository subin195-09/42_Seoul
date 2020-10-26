/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/26 21:38:26 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		divide_int(t_info info, va_list var)
{
	long long			ll_int;

	ll_int = 0;
	if (!info.count_l)
	{
		if (info.count_h == 1)
			ll_int = (short int)va_arg(var, int);
		else if (info.count_h >= 2)
			ll_int = (signed char)va_arg(var, int);
		else if (info.count_h == 0)
			ll_int = (int)va_arg(var, int);
	}
	else
	{
		if (info.count_l == 1)
			ll_int = (long)va_arg(var, long);
		else if (info.count_l >= 2)
			ll_int = (long long)va_arg(var, long long);
	}
	return (make_result_int(info, ll_int));
}

int		divide_uint(t_info *info, va_list var)
{
	unsigned long long	ull_int;

	info->check_sign = 0;
	info->space = 0;
	ull_int = 0;
	if (!info->count_l)
	{
		if (info->count_h == 1)
			ull_int = (unsigned short int)va_arg(var, int);
		else if (info->count_h >= 2)
			ull_int = (unsigned char)va_arg(var, int);
		else if (info->count_h == 0)
			ull_int = (unsigned int)va_arg(var, unsigned int);
	}
	else
	{
		if (info->count_l == 1)
			ull_int = (long unsigned)va_arg(var, long unsigned);
		else if (info->count_l >= 2)
		{
			ull_int = (long long)va_arg(var, long long);
			return (make_result_uint(*info, ull_int));
		}
	}
	return (make_result_int(*info, ull_int));
}

int		make_result(const char **format, t_info *info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'c')
		count_bytes = make_result_char(*info, var);
	if (**format == 's')
		count_bytes = make_result_string(*info, var);
	if (**format == 'd' || **format == 'i')
		count_bytes = divide_int(*info, var);
	if (**format == 'u')
		count_bytes = divide_uint(info, var);
	if (**format == 'x' || **format == 'X' || **format == 'o')
		count_bytes = make_result_base(*info, var, **format);
	if (**format == 'p')
	{
		info->padding = ' ';
		count_bytes = make_result_p(*info, var);
	}
	if (**format == '%')
		count_bytes = make_result_per(*info);
	(*format)++;
	return (count_bytes);
}
