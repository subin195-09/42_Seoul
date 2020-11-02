/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:08 by skim              #+#    #+#             */
/*   Updated: 2020/11/02 18:18:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_string(double num, int precision)
{

}

unsigned long long	standard_round(double num, int precision)
{

}

unsigned long long	banker_round(unsigned long long pre_num, unsigned long long ten, int precision)
{
	if (pre_num % 10 != 5)
		standard_round(pre_num, precision);
	else
	{
		ten = pre_num / 10;
		if (pre_num % 2)
			pre_num += 5;
		else
			pre_num -= 5;
	}

}
unsigned long long	round_checker(double num, int precision)
{
	unsigned long long	pre_num;
	unsigned long long	ten;
	t_double			t_num;

	ten = ft_pow(10, precision + 1);
	pre_num = num * ten;
	if ((t_num.mass << (precision + 13)) == 0)
		return (banker_round(pre_num, precision));
	else
		return (standard_round(pre_num, precision));
}

char				*ft_dtoa(double num, int precision)
{
	char		*result;
	char		*r_char;
	char		*pre_char;
	long		r_num;
	long long	pre_num;

	r_num = num;
	num -= num < 0 ? -r_num : r_num;
	pre_num = round_checker(num, precision) ? \
		banker_round(num, precision) : standard_round(num, precision);
	r_char = ft_ltoa(r_num);
	pre_char = make_string(num, precision);
	result = ft_strjoin(r_char, pre_char);
	free(r_char);
	free(pre_char);
	r_char = 0;
	pre_char = 0;
	return (result);
}
