/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:28:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/18 17:59:08 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*make_result_int_precision(s_info info, int num, int sign)
{
	char		*char_num;
	char		*result;
	long long	temp;
	int			size;
	int			i;

	if (!(result = malloc(sizeof(char) * (info.precision + sign + 1))))
		return (0);
	result[info.precision + sign] = '\0';
	temp = num;
	i = 0;
	if (sign)
	{
		temp = -temp;
		result[i++] = '-';
	}
	ft_memset(&result[i], '0', info.precision);
	char_num = ft_itoa(temp);
	size = ft_strlen(char_num) - 1;
	i = info.precision + sign - 1;
	while (size >= 0)
		result[i--] = char_num[size--];
	free(char_num);
	char_num = 0;
	return (result);
}

char	*make_result_int_width(s_info info, int num, int sign)
{
	char		*char_num;
	char		*result;
	long long	temp;
	int			size;
	int			i;

	if (!(result = malloc(sizeof(char) * info.width + 1)))
		return (0);
	result[info.width] = '\0';
	ft_memset(result, ' ', info.width);
	i = -1;
	if (info.precision)
	{
		char_num = make_result_int_precision(info, num, sign);
		while (info.left && char_num[++i])
			result[i] = char_num[i];
		size = ft_strlen(char_num) - 1;
		i = info.width - 1;
		while (!info.left && size >= 0)
			result[i--] = char_num[size--];
	}
	else
	{
		temp = num;
		if (sign)
			temp = -temp;
		char_num = ft_itoa(num);
		if (info.padding == '0' && !info.left)
		{
			ft_memset(result, '0', info.width);
			if (sign)
				result[++i] = '-';
			size = ft_strlen(char_num) - 1;
			i = info.width - 1;
			while (size >= 0)
				result[i--] = char_num[size--];
		}
		else
		{
			while (info.left && char_num[++i])
				result[i] = char_num[i];
			size = ft_strlen(char_num) - 1;
			i = info.width - 1;
			while (!info.left && size >= 0)
				result[i--] = char_num[size--];
		}
	}
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
	len = info.width > info.precision + sign ? \
		info.width : info.precision + sign;
	len = len > count ? len : count;
	if (len == count)
		result = ft_itoa(num);
	else if (info.precision + sign == len)
		result = make_result_int_precision(info, num, sign);
	else
		result = make_result_int_width(info, num, sign);
	num = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (num);
}
