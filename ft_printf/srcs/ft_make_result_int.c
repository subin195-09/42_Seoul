/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:27:51 by skim              #+#    #+#             */
/*   Updated: 2020/11/30 20:40:09 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*result_int_div(t_info info, long long num, int sign, int len)
{
	char	*result;
	char	*char_num;
	char	*char_width;
	int		count;

	count = count_num_long(num);
	char_num = num < 0 ? ft_ultoa(num * (-1)) : ft_ltoa(num);
	if (info.precision + sign == len)
		result = int_pre(info, char_num, sign, num);
	else
	{
		if (count < info.precision + sign)
			char_width = int_pre(info, char_num, sign, num);
		else
			char_width = ltoa_sign(num, sign);
		result = int_width(info, char_width, sign, num);
		free(char_width);
	}
	free(char_num);
	char_num = 0;
	return (result);
}

static char	*result_uint_div(t_info info, unsigned long long num, int len)
{
	char	*result;
	char	*char_num;
	char	*char_width;
	int		count;

	count = count_num_ulong(num);
	char_num = ft_ultoa(num);
	if (info.precision == len)
		result = int_pre(info, char_num, 0, num);
	else
	{
		if (count < info.precision)
			char_width = int_pre(info, char_num, 0, num);
		else
			char_width = ft_ultoa(num);
		result = int_width(info, char_width, 0, num);
		free(char_width);
	}
	free(char_num);
	char_num = 0;
	return (result);
}

int			make_result_int(t_info info, long long num)
{
	char	*result;
	int		sign;
	int		len;
	int		count;

	sign = (num < 0 || info.check_sign) ? 1 : 0;
	count = count_num_long(num) + sign;
	len = get_max(info.width, info.precision + sign, count);
	if (num == 0 && info.precision == 0)
		return (zero_check_int(info));
	if (len == count)
		result = ltoa_sign(num, sign);
	else
		result = result_int_div(info, num, sign, len);
	num = check_space(&result, len, sign, info);
	num += write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return ((int)num);
}

int			make_result_uint(t_info info, unsigned long long num)
{
	char	*result;
	int		len;
	int		count;

	count = count_num_ulong(num);
	len = get_max(info.width, info.precision, count);
	if (num == 0 && info.precision == 0)
		return (zero_check_int(info));
	if (len == count)
		result = ft_ultoa(num);
	else
		result = result_uint_div(info, num, len);
	num = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return ((int)num);
}
