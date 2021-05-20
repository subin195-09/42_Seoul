/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:47:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_r_b(t_stack *stk, int len, int pivot)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		if (stk->value >= pivot)
			return (0);
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
		count++;
	}
	return (count);
}

void	b_to_a(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	pivot;
	int	i;
	int	call_rb;
	int	call_rrb;
	int	call_pa;
	int	check;
	int	flag;

	// printf("b_to_a : %d\n", len);
	if (len == 0)
		return ;
	pivot = get_pivot(*b, len);
	i = -1;
	call_rb = 0;
	call_rrb = 0;
	call_pa = 0;
	flag = 0;
	if (len == info->size_b)
		flag = 1;
	while (++i < len)
	{
		// print_stack(*a, *b);
		// sleep(1);
		check = check_r_b(*b, len - i, pivot);
		if (len - i == 2 && (*b)->value < pivot && (*b)->prev->value >= pivot)
		{
			exec_ins(a, b, info, DO_SB);
			call_rb++;
			i++;
		}
		if ((*b)->value < pivot)
		{
			if (check == 0)
			{
				exec_ins(a, b, info, DO_RB);
				call_rrb++;
			}
			call_rb++;
		}
		else
		{
			exec_ins(a, b, info, DO_PA);
			call_pa++;
		}
	}
	i = -1;
	while (flag != 1 && ++i < call_rrb)
		exec_ins(a, b, info, DO_RRB);
	a_to_b(a, b, info, call_pa);
	b_to_a(a, b, info, call_rb);
}
