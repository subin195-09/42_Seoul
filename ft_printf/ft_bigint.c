/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 21:28:38 by skim              #+#    #+#             */
/*   Updated: 2020/11/01 21:51:40 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

typedef unsigned char *t_bigint;

int		make_bigint(int size, t_bigint *b_num)
{
	if (!(b_num = malloc(size + 1)))
		return (0);
}

void	make_fnum(double num, t_bigint *b_num, int precision)
{
	t_bigint 
}

int		round_bigint(double num, int precision)
{
	t_bigint	b_num;
	int			r_num;

	make_bigint(precision, &b_num);
	r_num = num;
	num -= r_num;
	make_fum(&num, &b_num, precision);

}
