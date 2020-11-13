/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:16:20 by skim              #+#    #+#             */
/*   Updated: 2020/11/13 22:37:56 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

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
	while (i < size)
	{
		if (man_bi[i++] == '1')
			add_arr(five, &man_de);
		mul_five(&five);
	}
	return (man_de);
}

void	ft_bigint(double num)
{
	t_uni	uni_num;
	int		exp;
	char	*manti;
	char	*result;
	int		i;
	int		j;

	uni_num.num = num;
	exp = uni_num.s_bit.exp - 1023;
	if (!(manti = malloc(1075)))
		return ;
	ft_memset(manti, '0', 1074);
	manti[1074] = 0;
	i = 0;
	printf("%d\n", exp);
	if (exp < 0)
	{
		i = -exp;
		manti[i - 1] = '1';
	}
	j = exp >= 0 ? 51 - exp : 51;
	while (j >= 0)
		manti[i++] = uni_num.s_bit.man >> j-- & 1 ? '1' : '0';
	result = change_demical(i + j, manti);
	printf("%s\n", result);
}
