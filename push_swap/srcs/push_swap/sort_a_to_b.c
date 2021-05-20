/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:24:32 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:50:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_r_a(t_stack *stk, int len, int pivot)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		if (stk->value < pivot)
			return (0);
		count++;
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
	}
	return (1);
}

void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	pivot;
	int	call[3];
	int	flag;
	int	i;

	if (len == 1 || check_asc(*a))
		return ;
	pivot = get_pivot(*a, len);
	ft_memset(call, 0, sizeof(call));
	flag = 0;
	if (len == info->size_a)
		flag = 1;
	i = -1;
	while (++i < len)
	{
		if (len == 2 && (*a)->value >= pivot && (*a)->prev->value < pivot)
		{
			exec_ins(a, b, info, DO_SA);
			call[C_R]++;
			i++;
		}
		if ((*a)->value >= pivot)
		{
			if (check_r_a(*a, len - i, pivot) == 0)
			{
				exec_ins(a, b, info, DO_RA);
				call[C_RR]++;
			}
			call[C_R]++;
		}
		else
		{
			exec_ins(a, b, info, DO_PB);
			call[C_P]++;
		}
	}
	while (flag != 1 && --call[C_RR] >= 0)
		exec_ins(a, b, info, DO_RRA);
	a_to_b(a, b, info, call[C_R]);
	b_to_a(a, b, info, call[C_P]);
}
