/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 20:10:03 by skim              #+#    #+#             */
/*   Updated: 2020/11/07 18:41:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*zero_precision_e(double num, int base, int exp)
{
	char	*result;
	char	*temp;
	int		r_num;
	double	m_num;

	r_num = num;
	m_num = num - r_num;
	if (exp > 0)
		num = (num + 5 * ft_pow(10, exp - 1)) / ft_pow(10, exp);
	else if (exp == 0)
		num += 0.5;
	else
	{
		r_num = m_num * ft_pow(10, -exp + 1);
		num = (r_num + 5) / 10;
	}
	if (base)
	{
		temp = ft_itoa((int)num);
		result = ft_strjoin(temp, ".");
		free(temp);
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

char	*ft_dtoa_e(double num, int precision, int base, int exp)
{
	char	*result;
	char	*r_char;
	char	*pre_char;
	long	r_num;
	t_ull	pre_num;

	if (precision + exp == 0)
		return (zero_precision_e(num, base, exp));
	r_num = (precision < 0 && exp > 0) ? \
		((int)num + (5 * ft_pow(10, exp - 2))) : num;
	num -= num < 0 ? -r_num : r_num;
	pre_num = round_checker(num, precision);
	if (count_num_ulong(pre_num) > precision && precision > 0)
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
