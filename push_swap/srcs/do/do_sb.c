/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:04:36 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:04:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_sb(t_stack **a, t_stack **b, t_info *info)
{
	int	tmp_value;

	if (info->size_b < 2)
		return ;
	tmp_value = (*b)->value;
	(*b)->value = (*b)->prev->value;
	(*b)->prev->value = tmp_value;
	(void)a;
}
