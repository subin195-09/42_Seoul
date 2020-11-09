/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 17:32:33 by skim              #+#    #+#             */
/*   Updated: 2020/10/28 05:29:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*cut_and_paste_char(char *var_char, t_info info)
{
	char	*result;
	char	padding;
	int		size;
	int		i;

	if (!(result = malloc(sizeof(char) * (info.width + 1))))
		return (0);
	result[info.width] = '\0';
	padding = info.left == 0 ? info.padding : ' ';
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

int			make_result_string(t_info info, va_list var)
{
	char	*result;
	char	*var_pre;
	char	*var_char;
	int		count_bytes;
	int		len;

	var_char = va_arg(var, char*);
	if (!var_char)
		var_char = "(null)";
	len = (int)ft_strlen(var_char);
	if (info.precision >= 0)
		len = info.precision < len ? info.precision : len;
	if (!(var_pre = malloc(len + 1)))
		return (0);
	ft_strlcpy(var_pre, var_char, len + 1);
	result = info.width > len ? \
		cut_and_paste_char(var_pre, info) : ft_strdup(var_pre);
	count_bytes = write(1, result, ft_strlen(result));
	free(var_pre);
	var_pre = 0;
	free(result);
	result = 0;
	return (count_bytes);
}

/*
static int	write_string(t_info info, char *var_char)
{
	char	*result;
	char	*var_pre;
	int		count_bytes;
	int		len;

	len = (int)ft_strlen(var_char);
	if (!(var_pre = malloc(len + 1)))
		return (0);
	ft_strlcpy(var_pre, var_char, len + 1);
	result = info.width > len ? \
		cut_and_paste_char(var_pre, info) : ft_strdup(var_pre);
	count_bytes = write(1, result, ft_strlen(result));
	free(var_pre);
	var_pre = 0;
	free(result);
	result = 0;
	return (count_bytes);
}

static int	w_size(int *var_num)
{
	int i;

	i = 0;
	while (var_num[i])
		i++;
	return (i);
}

int			make_result_string(t_info info, va_list var)
{
	char		*var_char;
	char		*var_temp;
	wchar_t		*var_num;
	int			pre;

	var_num = va_arg(var, wchar_t*);
	if (!var_num)
		return (write_string(info, "null"));
	pre = info.precision > -1 ? info.precision : w_size(var_num) * 4;
	var_temp = uni_encoder(*var_num, info.count_l, &pre);
	var_char = pre > 0 ? ft_strjoin("", var_temp) : ft_strdup("");
	free(var_temp);
	var_num++;
	while (*var_num && pre > 0)
	{
		var_temp = uni_encoder(*var_num, info.count_l, &pre);
		var_char = pre >= 0 ? ft_strjoin(var_char, var_temp) : var_char;
		free(var_temp);
		var_temp = 0;
		var_num++;
	}
	pre = write_string(info, var_char);
	free(var_char);
	var_char = 0;
	return (pre);
}
*/

int			make_result_char(t_info info, va_list var)
{
	char	*result;
	char	*var_char;
	wint_t	num;
	int		count_bytes;

	count_bytes = 0;
	num = va_arg(var, wint_t);
	if (!num)
		return (zero_check_char(info));
	var_char = uni_encoder(num, info.count_l, &count_bytes);
	if (info.width > 1)
	{
		result = cut_and_paste_char(var_char, info);
		count_bytes = write(1, result, ft_strlen(result));
		free(result);
		result = 0;
	}
	else
		count_bytes = write(1, var_char, ft_strlen(var_char));
	free(var_char);
	var_char = 0;
	return (count_bytes);
}
