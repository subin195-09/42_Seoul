/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:02:10 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:02:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_pa(t_stack **a, t_stack **b, t_info *info)
{
	if (info->size_b == 0)
		return ;
	if (!(*a))
		*a = new_stack_tail(0, (*b)->value);
	else
	{
		(*a)->next = new_stack_tail(*a, (*b)->value);
		*a = (*a)->next;
	}
	delete_stack(b);
	info->size_a++;
	info->size_b--;
}
