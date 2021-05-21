/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:06:07 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 16:17:39 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ra_or_rra(t_stack **a, t_stack **b, t_info *info, int kind)
{
	exec_ins(a, b, info, DO_SA);
	if (kind == DO_RA)
		exec_ins(a, b, info, DO_RA);
	else
		exec_ins(a, b, info, DO_RRA);
}

void	three_sort(t_stack **a, t_stack **b, t_info *info)
{
	int	max;
	int	min;

	max = find_max(*a, info->size_a);
	min = find_min(*a, info->size_a);
	if ((*a)->value == min)
	{
		if ((*a)->prev->value == max)
			sa_ra_or_rra(a, b, info, DO_RA);
	}
	else if ((*a)->value == max)
	{
		if ((*a)->prev->value == min)
			exec_ins(a, b, info, DO_RA);
		else
			sa_ra_or_rra(a, b, info, DO_RRA);
	}
	else
	{
		if ((*a)->prev->value == max)
			exec_ins(a, b, info, DO_RRA);
		else
			exec_ins(a, b, info, DO_SA);
	}
}

int		ra_or_rra(t_stack *a, t_info *info, int min)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value == min)
			break ;
		pos++;
		a = a->prev;
	}
	if (pos < info->size_a / 2)
		return (1);
	else
		return (-1);
}

void	less_sort(t_stack **a, t_stack **b, t_info *info)
{
	int		min;
	int		pos;

	if (check_asc(*a))
		return ;
	while (info->size_a != 3)
	{
		min = find_min(*a, info->size_a);
		pos = ra_or_rra(*a, info, min);
		if (pos > 0)
		{
			while ((*a)->value != min)
				exec_ins(a, b, info, DO_RA);
		}
		else
		{
			while ((*a)->value != min)
				exec_ins(a, b, info, DO_RRA);
		}
		exec_ins(a, b, info, DO_PB);
	}
	three_sort(a, b, info);
	while (info->size_b != 0)
		exec_ins(a, b, info, DO_PA);
}
