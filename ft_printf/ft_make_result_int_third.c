/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int_third.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 21:24:50 by skim              #+#    #+#             */
/*   Updated: 2020/10/27 21:23:21 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		get_max(int a, int b, int c)
{
	int max;

	max = a > b ? a : b;
	max = max > c ? max : c;
	return (max);
}

int		check_space(int len, int count, int sign, t_info info)
{
	if ((len == count || len == info.precision + sign) && info.space && !sign)
		return (write(1, " ", 1));
	else
		return (0);
}

int		zero_check_int(t_info info)
{
	char	*result;
	int		count_bytes;
	int		size;

	size = info.width > 1 ? info.width : 0;
	if (info.width <= 1)
	{
		if (info.check_sign)
			size++;
		else if (!info.check_sign && info.space)
			size++;
	}
	if (!(result = malloc(size + 1)))
		return (0);
	result[size] = '\0';
	ft_memset(result, ' ', size);
	if (info.check_sign)
	{
		size = info.left ? 0 : size - 1;
		result[size] = '+';
	}
	count_bytes = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (count_bytes);
}
