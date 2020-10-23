/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_hex_second.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 17:56:36 by skim              #+#    #+#             */
/*   Updated: 2020/10/23 18:09:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_num_hex(unsigned int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*change_hex(unsigned int num, int add)
{
	char	*result;
	char	hex_table[16];
	char	temp;
	int		i;

	i = 0;
	temp = '0';
	while (i < 10)
		hex_table[i++] = temp++;
	temp = 'a' + add;
	while (i < 16)
		hex_table[i++] = temp++;
	i = count_num_hex(num);
	if (!(result = malloc(i + 1)))
		return (0);
	result[i--] = '\0';
	if (num == 0)
		result[i--] = '0';
	while (num > 0 && i >= 0)
	{
		result[i--] = hex_table[num % 16];
		num /= 16;
	}
	return (result);
}
