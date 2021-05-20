/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 03:18:25 by skim             ###   ########.fr       */
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
	int	call[3];
	int	flag;

	if (len == 0)
		return ;
	pivot = get_pivot(*b, len);
	ft_memset(call, 0, sizeof(call));
	flag = 0;
	if (len == info->size_b)
		flag = 1;
	i = -1;
	while (++i < len)
	{
		if (len - i == 2 && (*b)->value < pivot && (*b)->prev->value >= pivot)
		{
			exec_ins(a, b, info, DO_SB);
			call[C_R]++;
			i++;
		}
		if ((*b)->value < pivot)
		{
			if (check_r_b(*b, len - i, pivot) == 0)
			{
				exec_ins(a, b, info, DO_RB);
				call[C_RR]++;
			}
			call[C_R]++;
		}
		else
		{
			exec_ins(a, b, info, DO_PA);
			call[C_P]++;
		}
	}
	while (flag != 1 && --call[C_RR] >= 0)
		exec_ins(a, b, info, DO_RRB);
	a_to_b(a, b, info, call[C_P]);
	b_to_a(a, b, info, call[C_R]);
}
