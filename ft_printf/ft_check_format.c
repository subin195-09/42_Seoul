/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/10/19 19:10:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void 	print_info(t_info info);

void	init_info(t_info *info)
{
	info->padding = '\0';
	info->width = 0;
	info->precision = 0;
	info->count_h = 0;
	info->count_l = 0;
	info->sign = 0;
	info->left = 0;
}

int		check_prewidth(const char **format)
{
	int prewidth;
	int temp;

	if (**format == '.')
		(*format)++;
	prewidth = ft_atoi(*format);
	temp = prewidth;
	while (temp > 0)
	{
		temp /= 10;
		(*format)++;
	}
	(*format)--;
	return (prewidth);
}

void	check_padding(const char **format, t_info *info)
{
	if (!info->padding || info->padding == ' ')
		info->padding = **format;
}

int		check_type(const char **format)
{
	if (**format == 'c' || **format == 'C')
		return (1);
	else if (**format == 's' || **format == 'S')
		return (1);
	else if (**format == 'p' || **format == 'P')
		return (1);
	else if (**format == 'd' || **format == 'i' ||
	**format == 'D' || **format == 'I')
		return (1);
	else if (**format == 'u' || **format == 'U')
		return (1);
	else if (**format == 'x' || **format == 'X')
		return (1);
	else if (**format == 'n' || **format == 'N')
		return (1);
	return (0);
}

int		check_specifier(const char **format, va_list var)
{
	int		count_bytes;
	t_info	info[1];

	init_info(info);
	while (**format && !check_type(format))
	{
		if (**format == 'l')
			info->count_l++;
		else if (**format == 'h')
			info->count_h++;
		else if (**format == ' ' || **format == '0')
			check_padding(format, info);
		else if (**format >= '1' && **format <= '9')
			info->width = check_prewidth(format);
		else if (**format == '.')
			info->precision = check_prewidth(format);
		else if (**format == '+')
			info->sign++;
		else if (**format == '-')
			info->left++;
		(*format)++;
	}
	print_info(*info);
	count_bytes = make_result(format, *info, var);
	return (count_bytes);
}

#include <stdio.h>

void print_info(t_info info)
{
	printf("padding : %c\n", info.padding);
	printf("width : %d\n", info.width);
	printf("precision : %d\n", info.precision);
	printf("sign : %d\n", info.sign);
	printf("left : %d\n", info.left);
}
