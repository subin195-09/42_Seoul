/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:48 by skim              #+#    #+#             */
/*   Updated: 2020/10/22 18:16:48 by skim             ###   ########.fr       */
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
		hex_table[i++] = temp++;
	temp = 'a' + add;
	while (i < 16)
		hex_table[i++] = temp++;
	i = count_num_hex(num);
	if (!(result = malloc(i + 1)))
		return (0);
	result[i--] = '\0';
	while (num > 0 && i >= 0)
	{
		result[i--] = hex_table[num % 16];
		num /= 16;
	}
	return (result);
}

char	*hex_precision(char *temp_num, int precision)
{
	char	*result;
	int		i;

	if (!(result = malloc(precision + 1)))
		return (0);
	result[precision] = '\0';
	ft_memset(result, '0', precision);
	i = ft_strlen(temp_num) - 1;
	while (i >= 0)
		result[--precision] = temp_num[i--];
	return (result);
}

char	*cut_and_paste_hex(char *temp_num, t_info info)
{
	char	*result;
	char	*temp_char;

	if (info.width > info.precision)
	{
		if (!info.precision)
			result = cut_and_paste_char(temp_num, info);
		else
		{
			temp_char = hex_precision(temp_num, info.precision);
			result = cut_and_paste_char(temp_char, info);
			free(temp_char);
			temp_char = 0;
		}
	}
	else
		result = hex_precision(temp_num, info.precision);
	return (result);
}

int		make_result_uint(t_info info, va_list var, char type)
{
	char			*result;
	char			*temp_num;
	unsigned int	num;
	int				count_bytes;
	int				add_x;

	num = va_arg(var, unsigned int);
	if (type == 'u')
		count_bytes = make_result_int(info, var); // int를 넘겨주기
	else
	{
		add_x = type == 'x' ? 0 : 'A' - 'a';
		temp_num = change_hex(num, add_x);
		result = cut_and_paste_hex(temp_num, info);
		count_bytes = write(1, result, ft_strlen(result));
	}
	return (count_bytes);
}
