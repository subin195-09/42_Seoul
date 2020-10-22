/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_int_second.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 21:05:55 by skim              #+#    #+#             */
/*   Updated: 2020/10/22 20:40:35 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	cut_and_paste_int(char **result, char *char_num, t_info info)
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

char	*itoa_with_sign(int num, int sign)
{
	char		*result;
	char		*char_num;
	long long	temp;
	int			i;
	int			j;

	temp = num;
	temp = temp > 0 ? temp : -temp;
	char_num = ft_itoa(temp);
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
