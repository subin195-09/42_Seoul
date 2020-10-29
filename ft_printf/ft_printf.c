/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:16:36 by skim              #+#    #+#             */
/*   Updated: 2020/10/29 21:38:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	make_result_n(va_list var, int bytes)
{
	int *store_bytes;

	store_bytes = va_arg(var, int *);
	*store_bytes = bytes;
}

static int	write_format(const char **format, va_list var)
{
	int		count_bytes;

	(*format)++;
	count_bytes = check_specifier(format, var);
	return (count_bytes);
}

int			ft_printf(const char *format, ...)
{
	va_list	var;
	int		count_bytes;
	int		rt_bytes;

	count_bytes = 0;
	va_start(var, format);
	while (*format)
	{
		if (*format != '%')
		{
			count_bytes += write(1, format, 1);
			format++;
		}
		else
		{
			rt_bytes = write_format(&format, var);
			if (rt_bytes == -1)
				make_result_n(var, count_bytes);
			else
				count_bytes += rt_bytes;
		}
	}
	va_end(var);
	return (count_bytes);
}
