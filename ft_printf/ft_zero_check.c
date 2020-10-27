/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 04:33:34 by skim              #+#    #+#             */
/*   Updated: 2020/10/28 04:40:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int		zero_check_char(t_info info)
{
	char	*result;
	int		size;
	int		count_bytes;

	count_bytes = 0;
	size = info.width > 1 ? info.width : 1;
	if (!(result = malloc(size)))
		return (0);
	ft_memset(result, ' ', size);
	if (info.width > 1)
	{
		if (info.left)
			result[0] = '\0';
		else
			result[size - 1] = '\0';
	}
	else
		result[size - 1] = '\0';
	count_bytes = write(1, result, size);
	free(result);
	result = 0;
	return (count_bytes);
}

int		zero_check_base(t_info info)
{
	int count_bytes;

	count_bytes = 0;
	if (info.width == -1)
		return (count_bytes);
	else
	{
		while (count_bytes < info.width)
			count_bytes += write(1, " ", 1);
		return (count_bytes);
	}
}
