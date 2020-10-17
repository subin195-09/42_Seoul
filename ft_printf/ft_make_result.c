/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:03:52 by skim              #+#    #+#             */
/*   Updated: 2020/10/17 17:57:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	cpy_result_int(char *result, s_info info, int num)
{
	int			sign;
	long long	temp;
	int			i;

	i = 0;
	sign = num >= 0 ? 0 : 1;
	temp = num;
	temp = temp >= 0 ? temp : -temp;
	if ((info.left || (!info.left && info.flag_in == '0')) && sign)
		result[i++] = '-';
	
}

char	*make_result_int(const char **format, s_info info, va_list var)
{
	int		num;
	char	*result;
	int		sign;
	int		len;

	num = va_arg(var, int);
	sign = num >= 0 ? 0 : 1;
	len = info.width > info.precision + 1 ? info.width : info.precision + 1;
	len = len > count_num(num) ? len : count_num(num);
	if (!(result = malloc(sizeof(char) * (len + 1))))
		return (0);
	result[len] = '\0';
	if (info.left || (!info.left && !info.flag_in) || info.precision)
		info.flag_in = ' ';
	ft_memset(result, info.flag_in, len);
	cpy_result_int(result, info, num);
}

int		make_result(const char **format, s_info info, va_list var)
{
	char *result;

	if (**format == 'd' || **format == 'i')
		result = make_result_int(**format, info, var);

}
