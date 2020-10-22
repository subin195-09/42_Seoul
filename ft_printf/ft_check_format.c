/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/10/22 19:18:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//지우기 지우기 지우기
void 	print_info(t_info info);

static void	init_info(t_info *info)
{
	info->padding = ' ';
	info->width = 0;
	info->precision = 0;
	info->count_h = 0;
	info->count_l = 0;
	info->check_sign = 0;
	info->left = 0;
}

static int	check_prewidth(const char **format, va_list var)
{
	int prewidth;
	int temp;

	if (**format == '.')
		(*format)++;
	if (**format == '*')
	{
		(*format)++;
		prewidth = va_arg(var, int);
	}
	else
	{
		prewidth = ft_atoi(*format);
		temp = prewidth;
		while (temp > 0)
		{
			temp /= 10;
			(*format)++;
		}
	}
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
	return (0);
}

int		check_specifier(const char **format, va_list var)
{
	int		count_bytes;
	t_info	info[1];

	count_bytes = 0;
	init_info(info);
	while (**format && !check_type(format))
	{
		if (**format == 'l')
			info->count_l++;
		else if (**format == 'h')
			info->count_h++;
		else if (**format == ' ' || **format == '0')
			info->padding = info->padding == ' ' ? **format : info->padding;
		else if ((**format >= '1' && **format <= '9') || **format == '*')
			info->width = check_prewidth(format, var);
		else if (**format == '.')
			info->precision = check_prewidth(format, var);
		else if (**format == '+')
			info->check_sign = 1;
		else if (**format == '-')
			info->left++;
		(*format)++;
	}
	//print_info(*info);
	if (**format)
		count_bytes = make_result(format, info, var);
	return (count_bytes);
}

#include <stdio.h>

void print_info(t_info info)
{
	printf("\n");
	printf("padding : %c\n", info.padding);
	printf("width : %d\n", info.width);
	printf("precision : %d\n", info.precision);
	printf("check_sign : %d\n", info.check_sign);
	printf("left : %d\n", info.left);
}
