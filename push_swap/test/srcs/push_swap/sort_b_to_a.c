/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:25:23 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 03:46:22 by skim             ###   ########.fr       */
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

int		init_call_b(t_stack *b, t_info *info, int call[7], int len)
{
	if (len == 0)
		return (0);
	ft_memset(call, 0, sizeof(int) * 7);
	call[C_LEN] = len;
	call[C_PI] = get_pivot(b, len);
	if (len == info->size_b)
		call[C_FL] = 1;
	call[C_I] = -1;
	return (1);
}

void	div_b_to_a(t_stack **a, t_stack **b, t_info *info, int call[7])
{
	if ((*b)->value < call[C_PI])
	{
		if (check_r_b(*b, call[C_LEN] - call[C_I], call[C_PI]) == 0)
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

void	b_to_a(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	call[7];

	if (init_call_b(*b, info, call, len) == 0)
		return ;
	while (++call[C_I] < call[C_LEN])
	{
		if (call[C_LEN] - call[C_I] == 2 && (*b)->value < call[C_PI] && \
		(*b)->prev->value >= call[C_PI])
		{
			exec_ins(a, b, info, DO_SB);
			call[C_R]++;
			call[C_I]++;
		}
		div_b_to_a(a, b, info, call);
	}
	while (call[C_FL] != 1 && --call[C_RR] >= 0)
		exec_ins(a, b, info, DO_RRB);
	a_to_b(a, b, info, call[C_P]);
	b_to_a(a, b, info, call[C_R]);
}
