/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 15:28:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/19 21:14:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*make_result_int_precision(t_info info, int num, int sign)
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
	temp = temp > 0 ? temp : -temp;
	i = 0;
	if (sign)
		result[i++] = num >= 0 ? '+' : '-';
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

static char		*make_result_int_width(t_info info, int num, int sign)
{
	char		*char_num;
	char		*result;

	if (!(result = malloc(sizeof(char) * info.width + 1)))
		return (0);
	result[info.width] = '\0';
	ft_memset(result, ' ', info.width);
	char_num = count_num(num) > info.precision + sign ? \
		itoa_with_sign(num, sign) : make_result_int_precision(info, num, sign);
	if (info.padding == '0' && !info.left)
	{
		ft_memset(result, '0', info.width);
		if (sign)
		{
			result[0] = num >= 0 ? '+' : '-';
			result++;
		}
		cut_and_paste_int(&result, char_num, info);
	}
	else
		cut_and_paste_int(&result, char_num, info);
	free(char_num);
	char_num = 0;
	return (result);
}

int				make_result_int(t_info info, va_list var)
{
	char	*result;
	int		num;
	int		sign;
	int		len;
	int		count;

	num = va_arg(var, int);
	sign = (num < 0 || info.check_sign) ? 1 : 0;
	count = count_num(num) + sign;
	len = info.width > info.precision + sign ? \
		info.width : info.precision + sign;
	len = len > count ? len : count;
	if (len == count)
		result = itoa_with_sign(num, sign);
	else if (info.precision + sign == len)
		result = make_result_int_precision(info, num, sign);
	else
		result = make_result_int_width(info, num, sign);
	num = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (num);
}
