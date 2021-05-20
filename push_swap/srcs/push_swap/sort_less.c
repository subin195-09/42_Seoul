/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:06:07 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:24:13 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// less sort 정렬 반대로 설정 해야함!!!!!!

void	three_sort(t_stack **a, t_stack **b, t_info *info)
{
	int	max;
	int	min;

	max = find_max(*a, info->size_a);
	min = find_min(*a, info->size_a);
	if ((*a)->value == max)
	{
		if ((*a)->prev->value == min)
		{
			exec_ins(a, b, info, DO_SA);
			exec_ins(a, b, info, DO_RA);
		}
	}
	else if ((*a)->value == min)
	{
		exec_ins(a, b, info, DO_RA);
		if ((*a)->value != max)
			exec_ins(a, b, info, DO_SA);
	}
	else
	{
		if ((*a)->prev->value == max)
			exec_ins(a, b, info, DO_SA);
		else
			exec_ins(a, b, info, DO_RRA);
	}
}

void	less_sort(t_stack **a, t_stack **b, t_info *info)
{
	int		max;
	int		pos;
	t_stack	*anc;

	if (check_asc(*a))
		return ;
	while (info->size_a != 3)
	{
		max = find_max(*a, info->size_a);
		pos = 0;
		anc = *a;
		while (anc)
		{
			if (anc->value == max)
				break ;
			pos++;
			anc = anc->prev;
		}
		if (pos < info->size_a / 2)
		{
			while ((*a)->value != max)
				exec_ins(a, b, info, DO_RA);
		}
		else
		{
			while ((*a)->value != max)
				exec_ins(a, b, info, DO_RRA);
		}
		exec_ins(a, b, info, DO_PB);
	}
	three_sort(a, b, info);
	while (info->size_b != 0)
		exec_ins(a, b, info, DO_PA);
}
