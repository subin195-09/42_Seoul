/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:00:31 by skim              #+#    #+#             */
/*   Updated: 2020/11/02 16:30:53 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result_float(t_info info, va_list var)
{
	char	*result;
	char	*char_num;
	double	num;
	int		sign;
	int		len;

	num = va_arg(var, double);
	len = info.precision > -1 ? info.precision : 6;
	char_num = ft_dtoa(num, len);
	sign = (num < 0 || info.check_sign) ? 1 : 0;
	// len = precisionㅇㅣ랑 길잊중 짧은 것을 선택
	len = len > sign + info.width ? len : sign + info.width;

}
