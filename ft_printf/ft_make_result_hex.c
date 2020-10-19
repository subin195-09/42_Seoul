/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:48 by skim              #+#    #+#             */
/*   Updated: 2020/10/20 00:13:55 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_num_hex(int num)
{
	int count;

	count = 0;
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*change_hex(int num, int add)
{
	char	*result;
	char	hex_table[16];
	char	temp;
	int		i;

	i = 0;
	temp = '0';
	while (i < 10)
		hex_table[i++] = temp + i;
	temp = 'a' + add;
	while (i < 16)
		hex_table[i++] = temp + i;
	if (!(result = malloc(count_num_hex(num) + 1)))
		return (0);
	i = 0;
	while (num > 0)
	{
		result[i++] = hex_table[num % 16];
		num /= 16;
	}
	result[i] = '\0';
	return (result);
}

int		make_result_uint(t_info info, va_list var, char type)
{
	char			*result;
	unsigned int	num;
	int				count_bytes;
	int				add_x;

	num = va_arg(var, unsigned int);
	if (type == 'u') //itoa 바꾼후 int함수 응용
		count_bytes = make_result_int(info, var); // 추후 수정
	else
	{
		add_x = type == 'x' ? 'A' - 'a' : 0;
		result = change_hex(num, add_x);
		// string 으로 result, info 보내기
	}
	return (count_bytes);
}
