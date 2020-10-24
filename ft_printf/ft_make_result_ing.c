/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_result_uint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:27:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/23 21:29:13 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			count_num_unit(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (count);
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}
