/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:08 by skim              #+#    #+#             */
/*   Updated: 2020/11/03 13:53:03 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_string(t_ull pre_num, double num, int precision)
{
	char	*result;
	char	*pre_char;
	int		pre_i;
	int		i;

	if (!(result = malloc(precision + 2)))
		return (0);
	result[precision + 1] = '\0';
	ft_memset(result, '0', precision + 1);
	result[0] = '.';
	pre_char = ft_ultoa(pre_num);
	i = 0;
	while (++i < precision)
	{
		if (0 != (int)(num * ft_pow(10, i)))
			break ;
	}
	pre_i = -1;
	while (pre_char[++pre_i])
		result[i++] = pre_char[pre_i];
	free(pre_char);
	pre_char = 0;
	return (result);
}

t_ull	banker_round(t_ull pre_num, t_ull ten)
{
	if (pre_num % 10 != 5)
		pre_num += 5;
	else
	{
		ten = pre_num / 10;
		if (ten % 2)
			pre_num += 5;
		else
			pre_num -= 5;
	}
	return (pre_num / 10);
}

t_ull	round_checker(double num, int precision)
{
	unsigned long long	pre_num;
	unsigned long long	ten;
	t_double			t_num;

	t_num.num = num;
	ten = ft_pow(10, precision + 1);
	pre_num = num * ten;
	if ((t_num.mass << (precision + 13)) == 0)
		return (banker_round(pre_num, ten));
	else
		return ((pre_num + 5) / 10);
}

char	*ft_dtoa(double num, int precision)
{
	char	*result;
	char	*r_char;
	char	*pre_char;
	long	r_num;
	t_ull	pre_num;

	r_num = num;
	num -= num < 0 ? -r_num : r_num;
	pre_num = round_checker(num, precision);
	if (count_num_ulong(pre_num) > precision)
	{
		r_num++;
		pre_num = 0;
		num = 0;
	}
	r_char = ft_ltoa(r_num);
	pre_char = make_string(pre_num, num, precision);
	result = ft_strjoin(r_char, pre_char);
	free(r_char);
	free(pre_char);
	r_char = 0;
	pre_char = 0;
	return (result);
}
