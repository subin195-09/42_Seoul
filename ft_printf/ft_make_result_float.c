/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:00:31 by skim              #+#    #+#             */
/*   Updated: 2020/11/03 17:45:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		what_is_sign(double num, t_info info)
{
	t_double	d_num;

	d_num.num = num;
	if (d_num.sign == 0 && !info.check_sign)
		return (0);
	if (d_num.sign == 1)
		return (1);
	else
		return (2);
}

char	*check_sign(t_info info, double num, int sign)
{
	char		*result;
	char		*char_num;
	int			len;

	len = info.precision > -1 ? info.precision : 6;
	char_num = num < 0 ? \
		ft_dtoa(-num, len, info.base) : ft_dtoa(num, len, info.base);
	if (sign == 1 || info.check_sign)
		result = sign == 1 ? \
			ft_strjoin("-", char_num) : ft_strjoin("+", char_num);
	else
		result = ft_strdup(char_num);
	free(char_num);
	char_num = 0;
	return (result);
}

char	*cut_and_paste_float(char *char_num, t_info info, int sign)
{
	char	*result;
	char	padding;
	int		stop;
	int		size;
	int		i;

	if (!(result = malloc(info.width + 1)))
		return (0);
	result[info.width] = '\0';
	padding = info.left ? ' ' : info.padding;
	ft_memset(result, padding, info.width);
	stop = 0;
	i = -1;
	if (sign && padding == '0')
	{
		result[0] = char_num[0];
		stop++;
	}
	while (info.left && char_num[++i])
		result[i] = char_num[i];
	size = ft_strlen(char_num);
	i = info.width;
	while (!info.left && --size >= stop)
		result[--i] = char_num[size];
	return (result);
}

int		make_result_float(t_info info, va_list var)
{
	char	*result;
	char	*char_num;
	double	num;
	int		len;
	int		sign;

	num = va_arg(var, double);
	sign = what_is_sign(num, info);
	char_num = check_sign(info, num, sign);
	len = ft_strlen(char_num);
	len = len > info.width ? len : info.width;
	if (len != info.width)
		result = ft_strdup(char_num);
	else
		result = cut_and_paste_float(char_num, info, sign);
	len = check_space(&result, len, sign, info);
	len += write(1, result, ft_strlen(result));
	free(result);
	free(char_num);
	result = 0;
	result = char_num;
	return (len);
}
