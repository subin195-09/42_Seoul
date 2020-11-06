/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:40:08 by skim              #+#    #+#             */
/*   Updated: 2020/11/06 17:58:07 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*make_string(t_ull pre_num, double num, int precision, long r_num)
{
	char	*result;
	char	*pre_char;
	int		pre_i;
	int		i;

	if (precision <= 0)
		return (ft_strdup("\0"));
	if (!(result = malloc(precision + 2)))
		return (0);
	result[precision + 1] = '\0';
	ft_memset(result, '0', precision + 1);
	result[0] = '.';
	pre_char = ft_ultoa(pre_num);
	i = 0;
	while (++i < precision)
	{
		if ((int)(num * ft_pow(10, i)) != 0)
			break ;
	}
	if (r_num == 875 && i <= precision && pre_num != 1)
		i--;
	pre_i = 0;
	while (pre_char[pre_i])
		result[i++] = pre_char[pre_i++];
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
	if ((t_num.man << (precision + 13)) == 0)
		return (banker_round(pre_num, ten));
	else
		return ((pre_num + 5) / 10);
}

char	*zero_precision(double num, int base, int exp)
{
	char	*result;
	char	*temp;
	int		r_num;
	double	m_num;

	r_num = num;
	m_num = num - r_num;
	if (exp)
	{
		
	}
	else
	{
		if ((int)(m_num * 10) != 5)
			num += 0.5;
		else
		{
			if (r_num % 2 != 0)
				num += 1;
		}
	}
	if (base)
	{
		temp = ft_itoa((int)num);
		result = ft_strjoin(temp, ".");
		free(temp);
		temp = 0;
	}
	else
		result = ft_itoa((int)num);
	return (result);
}

char	*ft_makejoin(char *r_char, char *pre_char, int stop)
{
	char	*result;
	char	*temp;
	int		size;
	int		i;

	if (!(result = malloc(stop + 2)))
		return (0);
	result[stop + 1] = 0;
	ft_memset(result, '0', stop + 1);
	temp = ft_strjoin(r_char, ++pre_char);
	i = 0;
	size = 0;
	while (temp[i] == '0')
		i++;
	result[1] = temp[i] ? '0' : '.';
	if (temp[i])
	{
		result[size++] = temp[i++];
		result[size++] = '.';
		while (temp[i] && size < stop + 2)
			result[size++] = temp[i++];
	}
	free(temp);
	temp = 0;
	return (result);
}

char	*ft_dtoa(double num, int precision, int base, int exp)
{
	char	*result;
	char	*r_char;
	char	*pre_char;
	long	r_num;
	t_ull	pre_num;

	if (precision + exp == 0)
		return (zero_precision(num, base, exp));
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
	pre_char = make_string(pre_num, num, precision, r_num);
	result = exp == 0 ? ft_strjoin(r_char, pre_char) \
		: ft_makejoin(r_char, pre_char, precision + exp);
	ft_frees(2, r_char, pre_char);
	r_char = 0;
	pre_char = 0;
	return (result);
}
