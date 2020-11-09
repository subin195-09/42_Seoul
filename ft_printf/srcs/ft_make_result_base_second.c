/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_base_second.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:36:55 by skim              #+#    #+#             */
/*   Updated: 2020/10/29 00:25:51 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_num_base(long long num, int base_len)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base_len;
		count++;
	}
	return (count);
}

char	*change_base(unsigned long long num, char *base)
{
	char	*result;
	int		base_len;
	int		size;

	base_len = ft_strlen(base);
	size = count_num_base(num, base_len);
	if (!(result = malloc(size + 1)))
		return (0);
	result[size--] = '\0';
	if (num == 0)
		result[size--] = '0';
	while (num > 0 && size >= 0)
	{
		result[size--] = base[num % base_len];
		num /= base_len;
	}
	return (result);
}
