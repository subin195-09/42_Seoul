/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:48 by skim              #+#    #+#             */
/*   Updated: 2020/10/23 19:31:14 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cut_and_paste_hex(char *var_char, t_info info)
{
	char	*result;
	char	padding;
	int		size;
	int		i;

	if (!(result = malloc(sizeof(char) * (info.width + 1))))
		return (0);
	result[info.width] = '\0';
	padding = info.precision > -1 ? ' ' : info.padding;
	i = 0;
	while (i < info.width)
		result[i++] = padding;
	i = -1;
	while (info.left && var_char[++i])
		result[i] = var_char[i];
	size = ft_strlen(var_char) - 1;
	i = info.width - 1;
	while (!info.left && size >= 0)
		result[i--] = var_char[size--];
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

char	*make_result_hex(char *temp_num, t_info info)
{
	char	*result;
	char	*temp_char;
	int		size;

	size = ft_strlen(temp_num);
	if (info.width > -1 && info.width > size)
	{
		if (info.precision > -1 && info.precision > size)
		{
			temp_char = hex_precision(temp_num, info.precision);
			result = cut_and_paste_hex(temp_char, info);
			free(temp_char);
			temp_char = 0;
		}
		else
			result = cut_and_paste_hex(temp_num, info);
	}
	else
	{
		if (info.precision > -1 && info.precision > size)
			result = hex_precision(temp_num, info.precision);
		else
			result = temp_num;
	}
	return (result);
}

int		make_result_x(t_info info, va_list var, char type)
{
	char			*result;
	char			*temp_num;
	unsigned int	num;
	int				count_bytes;
	int				add_x;

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
	add_x = type == 'x' ? 0 : 'A' - 'a';
	temp_num = change_hex(num, add_x);
	result = make_result_hex(temp_num, info);
	count_bytes = write(1, result, ft_strlen(result));
	return (count_bytes);
}
