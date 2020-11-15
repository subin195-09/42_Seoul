/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:16:20 by skim              #+#    #+#             */
/*   Updated: 2020/11/15 18:16:40 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	mul_five(char **five)
{
	int		len;
	int		tmp;
	int		carry;

	len = ft_strlen(*five);
	carry = 0;
	while (len >= 0)
	{
		tmp = len > 0 ? ((*five)[len - 1] - '0') * 5 : 0;
		(*five)[len] = (carry + tmp % 10) + '0';
		carry = tmp / 10;
		len--;
	}
}

void	add_arr(char *five, char **man_de)
{
	int		i;
	int		tmp;
	int		check;
	int		carry;

	i = ft_strlen(five) - 1;
	carry = 0;
	while (i >= 0)
	{
		tmp = (five[i] - '0') + ((*man_de)[i] - '0');
		check = carry + tmp % 10;
		(*man_de)[i] = check % 10 + '0';
		carry = check >= 10 ? (tmp / 10) + 1 : (tmp / 10);
		i--;
	}
}

char	*change_demical(int size, char *man_bi)
{
	char	*man_de;
	char	*five;
	int		i;

	if (!(five = ft_calloc(1074, sizeof(char))))
		return (0);
	if (!(man_de = malloc(1074 + 1)))
		return (0);
	ft_memset(man_de, '0', 1074);
	five[0] = '5';
	i = 0;
	while (i <= size)
	{
		if (man_bi[i++] == '1')
			add_arr(five, &man_de);
		mul_five(&five);
	}
	return (man_de);
}

char	*make_manti(t_uni uni_num)
{
	int		exp;
	char	*manti;
	char	*result;
	int		i;
	int		j;

	exp = uni_num.s_bit.exp - 1023;
	if (!(manti = malloc(1075)))
		return (0);
	ft_memset(manti, '0', 1074);
	manti[1074] = 0;
	i = 0;
	if (exp < 0)
	{
		i = -exp;
		manti[i - 1] = '1';
	}
	j = exp >= 0 ? 51 - exp : 51;
	while (j >= 0)
		manti[i++] = uni_num.s_bit.man >> j-- & 1 ? '1' : '0';
	result = change_demical(i + j, manti);
	ft_frees(1, manti);
	return (result);
}

char	*join_double(char *r_man, long r_num)
{
	char	*result;
	char	*temp_int;
	char	*add_point;

	temp_int = ft_ltoa(r_num);
	add_point = ft_strjoin(temp_int, ".");
	result = ft_strjoin(add_point, r_man);
	ft_frees(2, temp_int, add_point);
	return (result);
}

void	round_double(char **result, int pre)
{
	int check;
	int carry;
	int temp;
	int i;
	int j;

	i = 0;
	while ((*result)[i] != '.')
		i++;
	j = i + pre;
	carry = 0;
	while (j >= 0)
	{
		if ((*result)[j] != '.')
		{
			check = (*result)[j + 1] == '.' ? 1 : 0;
			carry = (*result)[j + 1 + check] - '0' + 5 >= 10 ? 1 : 0;
			temp = (*result)[j] - '0' + carry;
			(*result)[j] = temp % 10 + '0';
		}
		j--;
	}
}

void	ft_bigint(double num)
{
	char	*result;
	char	*r_man;
	t_uni	uni_num;
	long	r_num;
	double	d_num;

	r_num = num;
	d_num = num - r_num;
	uni_num.num = d_num;
	r_man = make_manti(uni_num);
	result = join_double(r_man, r_num);
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
	round_double(&result, 5);
	write(1, result, ft_strlen(result));
}
