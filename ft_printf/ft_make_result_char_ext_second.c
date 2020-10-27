/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_char_ext_second.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:15:49 by skim              #+#    #+#             */
/*   Updated: 2020/10/27 17:35:23 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		result_char_four(int num)
{
	unsigned char	*result;
	int				i;

	i = 4;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 240 | num;
	i--;
	i = write(1, result, 4);
	free(result);
	result = 0;
	return (i);
}

int		result_char_three(int num)
{
	char	*result;
	int		i;

	i = 3;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 224 | num;
	i--;
	i = write(1, result, 3);
	free(result);
	result = 0;
	return (i);
}

int		result_char_two(int num)
{
	char	*result;
	int		i;

	i = 2;
	if (!(result = malloc(i--)))
		return (0);
	result[i] = 63 & num;
	result[i] = 128 | result[i];
	i--;
	num = num >> 6;
	result[i] = 192 | num;
	i--;
	i = write(1, result, 2);
	free(result);
	result = 0;
	return (i);
}

int		write_result_ext(int num)
{
	int	count_bytes;

	count_bytes = 0;

	if (num < 128)
		count_bytes = write(1, &num, 1);
	else if (num >= 128 && num <= 2047)
		count_bytes = result_char_two(num);
	else if (num >= 2048 && num <= 65535)
		count_bytes = result_char_three(num);
	else if (num >= 65536 && num <= 2097151)
		count_bytes = result_char_four(num);
	return (count_bytes);
}
