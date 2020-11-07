/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_e.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 19:11:11 by skim              #+#    #+#             */
/*   Updated: 2020/11/07 17:07:52 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		count_exp(double num)
{
	int	exp;
	int	r_num;
	int	i;

	num = num > 0 ? num : -num;
	r_num = num;
	exp = r_num == 0 ? 1 : 0;
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
	}
	return (exp);
}

int		exp_round_check(double num, t_info info, int exp)
{
	int		precision;
	char	*round_num;
	int		i;
	int		ret;

	num = num > 0 ? num : -num;
	precision = info.precision > -1 ? info.precision - exp : 6 - exp;
	round_num = ft_dtoa_e(num, precision, 0, 0);
	if (precision >= 0)
	{
		i = 0;
		while (round_num[i] != '.' && round_num[i])
			i++;
	}
	else
		i = count_num((int)num + (5 * ft_pow(10, exp - 1)));
	if (i != count_num((int)num))
		ret = 1;
	else
		ret = 0;
	free(round_num);
	round_num = 0;
	return (ret);
}

char	*join_exp(char *char_no_exp, int exp, char type)
{
	char	*result;
	char	*char_exp;
	int		count;
	char	sign;

	sign = exp >= 0 ? '+' : '-';
	exp = exp > 0 ? exp : -exp;
	count = count_num(exp);
	count = count >= 2 ? count : 2;
	if (!(char_exp = malloc(count + 3)))
		return (0);
	ft_memset(char_exp, '0', count + 2);
	char_exp[count + 2] = '\0';
	char_exp[0] = type;
	char_exp[1] = sign;
	while (exp > 0)
	{
		char_exp[1 + count--] = exp % 10 + '0';
		exp /= 10;
	}
	result = ft_strjoin(char_no_exp, char_exp);
	free(char_exp);
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
	sign = what_is_sign(num, info);
	exp = num == 0 ? 0 : count_exp(num);
	exp += num == 0 ? 0 : exp_round_check(num, info, exp);
	char_no_exp = check_sign(info, num, sign, exp);
	char_num = join_exp(char_no_exp, exp, type);
	sign = float_factory(info, char_num, sign);
	free(char_no_exp);
	free(char_num);
	char_no_exp = 0;
	char_num = 0;
	return (sign);
}
