/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:11:11 by skim              #+#    #+#             */
/*   Updated: 2020/11/05 16:20:05 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_exp(double num)
{
	int exp;
	int r_num;
	int i;

	exp = 1;
	r_num = num;
	i = 1;
	if (r_num == 0)
	{
		while (r_num < 10)
		{
			r_num = num * ft_pow(10, i++);
			exp--;
		}
	}
	else
	{
		while (r_num >= 10)
		{
			r_num /= 10;
			exp++;
		}
		exp--;
	}
	return (exp);
}

char	*join_exp(char *char_no_exp, int exp, char type)
{
	char	*result;
	char	*char_exp;
	char	*temp;
	int		i;

	temp = ltoa_sign(exp, 1);
	if (!(char_exp = malloc(2 + ft_strlen(temp))))
		return (0);
	char_exp[0] = type;
	i = -1;
	while (temp[++i])
		char_exp[1 + i] = temp[i];
	char_exp[1 + i] = '\0';
	result = ft_strjoin(char_no_exp, char_exp);
	free(temp);
	free(char_exp);
	temp = 0;
	char_exp = 0;
	return (result);
}

int		make_result_e(t_info info, va_list var, char type)
{
	char	*char_num;
	char	*char_no_exp;
	double	num;
	int		sign;
	int		exp;

	num = va_arg(var, double);
	exp = count_exp(num);
	sign = what_is_sign(num, info);
	num = num * ft_pow(10, exp);
	char_no_exp = check_sign(info, num, sign);
	char_num = join_exp(char_no_exp, exp, type);
	sign = float_factory(info, char_num, sign);
	free(char_no_exp);
	free(char_num);
	char_no_exp = 0;
	char_num = 0;
	return (sign);
}
