/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:28:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/18 16:18:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_result_int_precision(s_info info, int num, int sign)
{
	char		*char_num;
	char		*result;
	long long	temp;
	int			size;

	if (!(result = malloc(sizeof(char) * (info.precision + sign + 1))))
		return (0);
	result[info.precision + sign] = '\0';
	temp = num;
	if (sign)
	{
		temp = -temp;
		*result++ = '-';
	}
	ft_memset(result, '0', info.precision);
	char_num = ft_itoa(temp);
	size = ft_strlen(char_num) + 1;
	char_num += size;
	result += info.precision;
	while (size--)
		*result-- = *char_num--;
	free(char_num);
	char_num = 0;
	return (result);
}

int		make_result_int(s_info info, va_list var)
{
	char	*result;
	int		num;
	int		sign;
	int		len;
	int		count;

	num = va_arg(var, int);
	sign = num >= 0 ? 0 : 1;
	count = count_num(num);
	len = info.width > info.precision + 1 ? info.width : info.precision + 1;
	len = len > count ? len : count;
	if (len == count)
		result = ft_itoa(num);
	else if (info.precision + sign == len)
		result = make_result_int_precision(info, num, sign);
	//else if (info.width == len)
	//	result = make_result_int_width(info, num);
	else
		result = 0;
	num = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (num);
}
