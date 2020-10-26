/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_o.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:03:50 by skim              #+#    #+#             */
/*   Updated: 2020/10/26 15:37:12 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		make_result_o(t_info info, va_list var)
{
	char			*result;
	char			*temp_num;
	unsigned int	num;
	int				count_bytes;

	num = va_arg(var, unsigned int);
	count_bytes = 0;
	if (!num && !info.precision)
	{
		if (info.width == -1)
			return (count_bytes);
		else
		{
			while (count_bytes < info.width)
				count_bytes += write(1, " ", 1);
			return (count_bytes);
		}
	}
	temp_num = change_base(num, "01234567");
	result = make_result_hex(temp_num, info);
	count_bytes = write(1, result, ft_strlen(result));
	return (count_bytes);
}
