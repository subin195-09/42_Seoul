/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 22:08:48 by skim              #+#    #+#             */
/*   Updated: 2020/10/26 23:00:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*cut_and_paste_base(char *var_char, t_info info)
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

char	*base_precision(char *temp_num, int precision)
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

int		write_result(char *temp_num, t_info info)
{
	char	*result;
	char	*temp_char;
	int		size;

	size = ft_strlen(temp_num);
	if (info.width > size)
	{
		if (info.precision > size)
		{
			temp_char = base_precision(temp_num, info.precision);
			result = cut_and_paste_base(temp_char, info);
			free(temp_char);
			temp_char = 0;
		}
		else
			result = cut_and_paste_base(temp_num, info);
	}
	else
		result = info.precision > size ? \
			base_precision(temp_num, info.precision) : ft_strdup(temp_num);
	size = write(1, result, ft_strlen(result));
	free(result);
	result = 0;
	return (size);
}

int		check_base(t_info info, char type)
{

}

int		make_result_base(t_info info, unsigned long long num, char type)
{
	char			*temp_num;
	int				count_bytes;

	count_bytes = 0;
	if (!num && !info.precision)
		return (zero_check_base(info));
	if (type == 'x')
		temp_num = change_base(num, "0123456789abcdef");
	else if (type == 'X')
		temp_num = change_base(num, "0123456789ABCDEF");
	else
		temp_num = change_base(num, "01234567");
	count_bytes = check_base(info, type);
	count_bytes = write_result(temp_num, info);
	free(temp_num);
	temp_num = 0;
	return (count_bytes);
}
