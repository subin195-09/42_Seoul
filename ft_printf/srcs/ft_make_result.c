/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/11/09 17:32:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	divide_int(t_info info, va_list var)
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

static int	divide_uint(t_info *info, va_list var, char type)
{
	unsigned long long	ull_int;

	info->check_sign = 0;
	info->space = 0;
	if (!info->count_l)
	{
		if (info->count_h == 1)
			ull_int = (unsigned short int)va_arg(var, int);
		else if (info->count_h >= 2)
			ull_int = (unsigned char)va_arg(var, int);
		else
			ull_int = (unsigned int)va_arg(var, unsigned int);
	}
	else
	{
		if (info->count_l == 1)
			ull_int = (long unsigned)va_arg(var, long unsigned);
		else
			ull_int = (long long)va_arg(var, long long);
	}
	if (type == 'u')
		return (make_result_uint(*info, ull_int));
	else
		return (make_result_base(info, ull_int, type));
}

static int	make_result_two(const char **format, t_info *info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'c')
		count_bytes = make_result_char(*info, var);
	else if (**format == 's')
		count_bytes = make_result_string(*info, var);
	else if (**format == 'p')
	{
		info->padding = ' ';
		count_bytes = make_result_p(*info, var);
	}
	else if (**format == '%')
		count_bytes = make_result_per(*info);
	return (count_bytes);
}

int			make_result(const char **format, t_info *info, va_list var)
{
	int count_bytes;

	count_bytes = 0;
	if (**format == 'd' || **format == 'i')
		count_bytes = divide_int(*info, var);
	else if (**format == 'u' || \
		**format == 'x' || **format == 'X' || **format == 'o')
		count_bytes = divide_uint(info, var, **format);
	else if (**format == 'n')
		count_bytes = -1;
	else if (**format == 'f')
		count_bytes = make_result_double(*info, var);
	else if (**format == 'e' || **format == 'E')
		count_bytes = make_result_e(*info, var, **format);
	else if (**format == 'c' || **format == 's' || **format == 'p' || \
		**format == ' ' || **format == '%')
		count_bytes = make_result_two(format, info, var);
	(*format)++;
	return (count_bytes);
}
