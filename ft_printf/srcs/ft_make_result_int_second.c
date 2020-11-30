/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int_second.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:42:57 by skim              #+#    #+#             */
/*   Updated: 2020/11/30 20:06:52 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	cut_and_paste_int(char **result, char *char_num, t_info info)
{
	int stop;
	int size;
	int i;

	i = -1;
	stop = 0;
	if ((*result)[0] == '+' || (*result)[0] == '-')
	{
		i++;
		stop++;
	}
	while (info.left && char_num[++i])
		(*result)[i] = char_num[i];
	size = ft_strlen(char_num) - 1;
	i = ft_strlen(*result) - 1;
	while (!info.left && size >= stop)
		(*result)[i--] = char_num[size--];
}

char		*int_width(t_info info, char *char_num, int sign, long long num)
{
	char		*result;

	if (!(result = malloc(sizeof(char) * (info.width + 1))))
		return (0);
	result[info.width] = '\0';
	ft_memset(result, ' ', info.width);
	if (info.padding == '0' && !info.left && info.precision < 0)
	{
		ft_memset(result, '0', info.width);
		if (sign)
			*result = num >= 0 ? '+' : '-';
		cut_and_paste_int(&result, char_num, info);
	}
	else
		cut_and_paste_int(&result, char_num, info);
	return (result);
}

char		*int_pre(t_info info, char *char_num, int sign, long long num)
{
	char		*result;
	int			size;
	int			i;

	if (!(result = malloc(sizeof(char) * (info.precision + sign + 1))))
		return (0);
	result[info.precision + sign] = '\0';
	i = 0;
	if (sign)
		result[i++] = num >= 0 ? '+' : '-';
	ft_memset(&result[i], '0', info.precision);
	size = ft_strlen(char_num) - 1;
	i = info.precision + sign - 1;
	while (size >= 0)
		result[i--] = char_num[size--];
	return (result);
}

char		*ltoa_sign(long long num, int sign)
{
	char				*result;
	char				*char_num;
	unsigned long long	temp;
	int					i;
	int					j;

	temp = num > 0 ? num : -num;
	char_num = ft_ultoa(temp);
	if (!(result = malloc(ft_strlen(char_num) + sign + 1)))
		return (0);
	i = 0;
	j = 0;
	if (sign)
		result[i++] = num >= 0 ? '+' : '-';
	while (char_num[j])
		result[i++] = char_num[j++];
	result[i] = '\0';
	free(char_num);
	char_num = 0;
	return (result);
}
