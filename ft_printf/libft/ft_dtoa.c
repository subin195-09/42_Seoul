/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:08 by skim              #+#    #+#             */
/*   Updated: 2020/11/02 21:03:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_string(ull num, int precision)
{
	char	*result;
	char	*pre_char;

	pre_char = ft_ultoa(num);
	result = ft_strjoin(".", pre_char);
	free(pre_char);
	pre_char = 0;
	return (result);
}

ull		standard_round(ull pre_num, ull ten, int precision)
{
	if (pre_num % 10 < 5)
		pre_num -= 5;
	else
		pre_num += 5;
	return (pre_num / (ten / 10));
}

ull		banker_round(ull pre_num, ull ten, int precision)
{
	if (pre_num % 10 != 5)
		standard_round(pre_num, ten, precision);
	else
	{
		ten = pre_num / 10;
		if (pre_num % 2)
			pre_num += 5;
		else
			pre_num -= 5;
	}
	return (pre_num / (ten / 10));
}

ull		round_checker(double num, int precision)
{
	unsigned long long	pre_num;
	unsigned long long	ten;
	t_double			t_num;

	t_num.num = num;
	ten = ft_pow(10, precision + 1);
	pre_num = num * ten;
	if ((t_num.mass << (precision + 13)) == 0)
		return (banker_round(pre_num, ten, precision));
	else
		return (standard_round(pre_num, ten, precision));
}

char	*ft_dtoa(double num, int precision)
{
	char	*result;
	char	*r_char;
	char	*pre_char;
	long	r_num;
	ull		pre_num;

	r_num = num;
	num -= num < 0 ? -r_num : r_num;
	pre_num = round_checker(num, precision);
	r_char = ft_ltoa(r_num);
	pre_char = make_string(pre_num, precision);
	result = ft_strjoin(r_char, pre_char);
	free(r_char);
	free(pre_char);
	r_char = 0;
	pre_char = 0;
	return (result);
}
