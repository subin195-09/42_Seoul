/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:16:36 by skim              #+#    #+#             */
/*   Updated: 2020/10/14 23:27:44 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		write_format(const char **format, va_list var)
{
	int		count_bytes;

	count_bytes = 0;
	(*format)++;
	// flag의 글자수 만큼 format 위치를
	(*format) += check_flag(format);
	return (count_bytes);
}

// int		ft_printf(const char *format, ...)
// {
// 	// va_list	var;
// 	// int		count_bytes;

// 	// count_bytes = 0;
// 	// va_start(var, format);
// 	// while (*format)
// 	// {
// 	// 	if (*format != '%')
// 	// 		count_bytes += write(1, format, 1);
// 	// 	else
// 	// 		count_bytes += write_format(&format, var);
// 	// 	format++;
// 	// }
// 	// va_end(var);
// 	// return (count_bytes);
// }
