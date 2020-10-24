/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 15:40:04 by skim              #+#    #+#             */
/*   Updated: 2020/10/24 17:23:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_num_p(long long num)
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

char	*change_hex_p(long long num)
{
	char	*result;
	char	hex_table[16];
	char	temp;
	int		i;

	i = 0;
	temp = '0';
	while (i < 10)
		hex_table[i++] = temp++;
	temp = 'a';
	while (i < 16)
		hex_table[i++] = temp++;
	i = count_num_p(num);
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

char	*cut_and_paste_p(t_info info, long long num)
{
	char	*result;
	char	*hex_num;
	char	*with_pre;
	char	*temp;

	hex_num = change_hex_p(num);
	if (info.precision > -1 && info.precision > (int)ft_strlen(hex_num))
	{
		with_pre = hex_precision(hex_num, info.precision);
		temp = ft_strjoin("0x", with_pre);
		free(with_pre);
		with_pre = 0;
	}
	else
		temp = ft_strjoin("0x", hex_num);
	if (info.width > (int)ft_strlen(temp))
		result = cut_and_paste_hex(temp, info);
	else
		result = temp;
	free(hex_num);
	free(temp);
	hex_num = 0;
	temp = 0;
	return (result);
}

int		make_result_p(t_info info, va_list var)
{
	char			*result;
	unsigned char	*temp;
	void			*ptr;
	int				count_bytes;

	ptr = va_arg(var, void*);
	temp = (unsigned char*)ptr;
	result = cut_and_paste_p(info, (long long)temp);
	count_bytes = write(1, result, ft_strlen(result));
	return (count_bytes);
}
