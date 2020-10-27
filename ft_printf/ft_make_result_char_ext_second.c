/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_char_ext_second.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:15:49 by skim              #+#    #+#             */
/*   Updated: 2020/10/27 22:44:34 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

char	*result_char_four(int num)
{
	unsigned char	*result;
	int				i;

	i = 4;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 240 | num;
	return (result);
}

char	*result_char_three(int num)
{
	char	*result;
	int		i;

	i = 3;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 224 | num;
	return (result);
}

char	*result_char_two(int num)
{
	char	*result;
	int		i;

	i = 2;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 192 | num;
	return (result);
}

// num 으로 받아볼까?
int		make_result_char_extend(t_info info, va_list var)
{
	char	*result;
	int		num;

	num = va_arg(var, wint_t);
	if (num < 128)
	{
		if (!(result = malloc(2)))
			return (0);
		result[1] = '\0';
		result[0] = num;
	}
	else if (num >= 128 && num <= 2047)
		result = result_char_two(num);
	else if (num >= 2048 && num <= 65535)
		result = result_char_three(num);
	else if (num >= 65536 && num <= 2097151)
		result = result_char_four(num);
	// num = 출력
	return (num);
}
