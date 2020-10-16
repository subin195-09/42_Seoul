/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/10/16 18:34:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	init_info(s_info info)
{
	info.flag_in = '\0';
	info.width = 0;
}

int		check_width(const char **format)
{
	int width;
	int temp;

	width = ft_atoi(*format);
	temp = width;
	while (temp > 0)
	{
		temp /= 10;
		*format++;
	}
	return (width);
}

int		check_type(const char **format)
{
	if (**format == 'c' || **format == 'C')
		return (1);
	if (**format == 's' || **format == 'S')
		return (1);
	if (**format == 'p' || **format == 'P')
		return (1);
	if (**format == 'd' || **format == 'i' ||
	**format == 'D' || **format == 'I')
		return (1);
	if (**format == 'u' || **format == 'U')
		return (1);
	if (**format == 'x' || **format == 'X')
		return (1);
	if (**format == 'n' || **format == 'N')
		return (1);
	if (**format == 'f' || **format == 'F')
		return (1);
	if (**format == 'g' || **format == 'G')
		return (1);
	if (**format == 'e' || **format == 'E')
		return (1);
	if (**format == 'o' || **format == 'O')
		return (1);
	return (0);
}

int		check_specifier(const char **format, va_list var)
{
	int		count_bytes;
	s_info	info;

	count_bytes = 0;
	while (**format && !check_type(format))
	{
		if (**format == 'l')
			return (0);
		if (**format == ' ' || **format == '0')
		{
			info.flag_in = **format;
			*format++;
		}
		if (**format >= '1' && **format <= '9')
			info.width = (check_type(**format));
		if (**format == '+')
			return (0);
		if (**format == '.')
			return (0);
		if (**format == '#')
			return (0);
	}
	format_write(format, var, info);
	return (count_bytes);
}
