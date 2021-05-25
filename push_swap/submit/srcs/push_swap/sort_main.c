/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:43:38 by skim              #+#    #+#             */
/*   Updated: 2021/05/25 15:19:12 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_min(t_stack *a, int len)
{
	int	min;
	int	i;

	min = a->value;
	i = -1;
	while (++i < len)
	{
		if (a->value <= min)
			min = a->value;
		if (a->prev)
			a = a->prev;
		else
			break ;
	}
	return (min);
}

int		find_max(t_stack *a, int len)
{
	int	max;
	int	i;

	max = a->value;
	i = -1;
	while (++i < len)
	{
		if (a->value >= max)
			max = a->value;
		if (a->prev)
			a = a->prev;
		else
			break ;
	}
	return (max);
}

int		get_pivot(t_stack *stk, int len)
{
	int	min;
	int	max;

	min = find_min(stk, len);
	max = find_max(stk, len);
	if (max - min == 1)
		return (max);
	return ((max + min) / 2);
}

int		check_asc(t_stack *stk)
{
	while (stk->prev)
	{
		if (stk->value > stk->prev->value)
			return (0);
		stk = stk->prev;
	}
	return (1);
}

void	stack_sort(t_stack **a, t_stack **b, t_info *info)
{
	if (info->size_a < 20)
		less_sort(a, b, info);
	else
		a_to_b(a, b, info, info->size_a);
}
