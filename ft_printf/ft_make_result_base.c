/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:48 by skim              #+#    #+#             */
/*   Updated: 2020/10/29 21:50:13 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*base_join(char type, char *temp_num, t_info info)
{
	char *result;

	if (info.base > 0)
	{
		if (type == 'x')
			result = ft_strjoin("0x", temp_num);
		else if (type == 'X')
			result = ft_strjoin("0X", temp_num);
		else
			result = ft_strjoin("0", temp_num);
	}
	else
		result = ft_strdup(temp_num);
	return (result);
}

char	*cut_and_paste_base(char *var_char, t_info info, char type)
{
	char	*result;
	char	padding;
	int		size;
	int		i;

	if (!(result = calloc(sizeof(char), info.width + 1)))
		return (0);
	padding = (info.precision > -1 || info.left) ? ' ' : info.padding;
	i = -1;
	size = -1;
	ft_memset(result, padding, info.width);
	if (info.base && type != 'p')
	{
		i = (info.left || padding == '0') ? \
			-1 : info.width - ft_strlen(var_char) - 3;
		result[++i] = '0';
		result[++i] = type;
	}
	while (info.left && var_char[++size])
		result[++i] = var_char[size];
	size = ft_strlen(var_char) - 1;
	i = info.width - 1;
	while (!info.left && size >= 0)
		result[i--] = var_char[size--];
	return (result);
}

char	*base_precision(char *temp_num, t_info info, char type)
{
	char	*result;
	int		base;
	int		i;

	base = info.base > 0 ? 2 : 0;
	if (!(result = malloc(info.precision + base + 1)))
		return (0);
	result[info.precision + base] = '\0';
	ft_memset(result, '0', info.precision + base);
	i = ft_strlen(temp_num) - 1;
	while (i >= 0)
		result[--info.precision + base] = temp_num[i--];
	if (info.base > 0)
	{
		result[1] = type != 'o' ? type : result[i];
		result[0] = '0';
	}
	return (result);
}

int		write_result(char *temp_num, t_info info, char type)
{
	char	*result;
	char	*temp_char;
	int		size;
	int		base;

	size = ft_strlen(temp_num);
	base = info.base > 0 ? 2 : 0;
	if (info.width > size + base)
	{
		if (info.precision > size)
		{
			temp_char = base_precision(temp_num, info, type);
			result = cut_and_paste_base(temp_char, info, 'p');
			free(temp_char);
			temp_char = 0;
		}
		else
			result = cut_and_paste_base(temp_num, info, type);
	}
	else
		result = info.precision > size ? base_precision(temp_num, info, type) \
			: base_join(type, temp_num, info);
	size += write(1, result, ft_strlen(result));
	free(result);
	return (size);
}

int		make_result_base(t_info *info, unsigned long long num, char type)
{
	char			*temp_num;
	int				count_bytes;

	count_bytes = 0;
	if (!num)
	{
		if (!info->precision)
			return (zero_check_base(*info));
		info->base = 0;
	}
	if (type == 'x')
		temp_num = change_base(num, "0123456789abcdef");
	else if (type == 'X')
		temp_num = change_base(num, "0123456789ABCDEF");
	else
		temp_num = change_base(num, "01234567");
	count_bytes = write_result(temp_num, *info, type);
	free(temp_num);
	temp_num = 0;
	return (count_bytes);
}
