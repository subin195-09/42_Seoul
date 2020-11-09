/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/11/09 17:57:55 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	init_info(t_info *info)
{
	info->padding = ' ';
	info->space = 0;
	info->width = -1;
	info->precision = -1;
	info->count_h = 0;
	info->count_l = 0;
	info->check_sign = 0;
	info->left = 0;
	info->base = 0;
}

static int	check_prewidth(const char **format, va_list var, t_info *info)
{
	int prewidth;
	int flag;

	flag = 1;
	if (**format == '.')
	{
		(*format)++;
		flag = 0;
	}
	prewidth = **format == '*' ? va_arg(var, int) : ft_atoi(*format);
	if (**format == '*')
	{
		(*format)++;
		if (prewidth < 0 && flag == 1)
		{
			info->left = 1;
			prewidth *= -1;
		}
	}
	else
		while (**format >= '0' && **format <= '9')
			(*format)++;
	(*format)--;
	return (prewidth);
}

static int	check_type(const char **format)
{
	if (**format == 'c')
		return (1);
	else if (**format == 's')
		return (1);
	else if (**format == 'p')
		return (1);
	else if (**format == 'd' || **format == 'i')
		return (1);
	else if (**format == 'u')
		return (1);
	else if (**format == 'x' || **format == 'X')
		return (1);
	else if (**format == '%')
		return (1);
	else if (**format == 'o')
		return (1);
	else if (**format == 'n')
		return (1);
	else if (**format == 'f')
		return (1);
	else if (**format == 'e' || **format == 'E')
		return (1);
	return (0);
}

static void	check_padding(const char **format, t_info *info)
{
	if (**format == ' ')
		info->space++;
	if (info->padding == ' ')
		info->padding = **format;
}

int			check_specifier(const char **format, va_list var)
{
	int		count_bytes;
	t_info	info[1];

	count_bytes = 0;
	init_info(info);
	while (**format && !check_type(format))
	{
		if (**format == 'l' || **format == 'h')
			**format == 'l' ? info->count_l++ : info->count_h++;
		else if (**format == ' ' || **format == '0')
			check_padding(format, info);
		else if ((**format >= '1' && **format <= '9') || **format == '*')
			info->width = check_prewidth(format, var, info);
		else if (**format == '.')
			info->precision = check_prewidth(format, var, info);
		else if (**format == '+')
			info->check_sign = 1;
		else if (**format == '-' || **format == '#')
			**format == '-' ? info->left++ : info->base++;
		(*format)++;
	}
	if (**format)
		count_bytes = make_result(format, info, var);
	return (count_bytes);
}
