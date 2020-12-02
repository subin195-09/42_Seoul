/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:48:47 by skim              #+#    #+#             */
/*   Updated: 2020/12/02 15:32:31 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*bs_join(char type, char *temp_num, t_info info)
{
	char	*result;
	char	*temp;
	int		i;

	i = 0;
	if (info.base > 0 && type != 'p')
	{
		while (temp_num[i] == ' ')
			i++;
		if (!(temp = calloc(sizeof(char), i + 2 + 1)))
			return (0);
		ft_memset(temp, ' ', i + 2);
		temp[i] = '0';
		temp[i + 1] = type == 'o' ? temp[i + 1] : type;
		if (type == 'x')
			result = ft_strjoin(temp, temp_num + i);
		else if (type == 'X')
			result = ft_strjoin(temp, temp_num + i);
		else
			result = ft_strjoin(temp, temp_num + i);
		free(temp);
	}
	else
		result = ft_strdup(temp_num);
	return (result);
}

char		*cut_and_paste_base(char *var_char, t_info info, char type)
{
	char	*result;
	char	*result_base;
	char	padding;
	int		base;
	int		i;

	base = info.base > 0 ? 2 : 0;
	if (!(result = calloc(sizeof(char), info.width - base + 1)))
		return (0);
	padding = (info.precision > -1 || info.left) ? ' ' : info.padding;
	ft_memset(result, padding, info.width - base);
	i = -1;
	base = -1;
	while (info.left && var_char[++base])
		result[++i] = var_char[base];
	base = ft_strlen(var_char) - 1;
	i = info.base > 0 ? info.width - 2 : info.width;
	while (!info.left && base >= 0)
		result[--i] = var_char[base--];
	result_base = bs_join(type, result, info);
	free(result);
	result = 0;
	return (result_base);
}

char		*base_precision(char *temp_num, t_info info)
{
	char	*result;
	int		i;

	if (!(result = malloc(info.precision + 1)))
		return (0);
	result[info.precision] = '\0';
	ft_memset(result, '0', info.precision);
	i = ft_strlen(temp_num) - 1;
	while (i >= 0)
		result[--info.precision] = temp_num[i--];
	return (result);
}

static int	write_result(char *temp_num, t_info info, char type)
{
	char	*result;
	char	*temp_char;
	int		len;
	int		size;
	int		base;

	len = ft_strlen(temp_num);
	base = info.base > 0 ? 2 : 0;
	size = get_max(len + base, info.precision + base, info.width);
	if (size == len + base)
		temp_char = ft_strdup(temp_num);
	else if (size == info.precision + base)
		temp_char = base_precision(temp_num, info);
	else
		temp_char = info.precision > len ?\
		base_precision(temp_num, info) : ft_strdup(temp_num);
	result = (size == len + base || size == info.precision + base) ? \
	bs_join(type, temp_char, info) : cut_and_paste_base(temp_char, info, type);
	size = write(1, result, ft_strlen(result));
	free(result);
	free(temp_char);
	result = 0;
	temp_char = 0;
	return (size);
}

int			make_result_base(t_info *info, unsigned long long num, char type)
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
