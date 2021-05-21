/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:24:32 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 20:56:16 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int		init_call_a(t_stack *a, t_info *info, int call[7], int len)
{
	if (len == 1 || check_asc(a))
		return (0);
	ft_memset(call, 0, sizeof(int) * 7);
	call[C_LEN] = len;
	call[C_PI] = get_pivot(a, len);
	if (len == info->size_a)
		call[C_FL] = 1;
	call[C_I] = -1;
	return (1);
}

int		len_is_ra_or_rra(t_stack *a, int pivot)
{
	int	pos_ra;
	int	pos_rra;

	pos_ra = 0;
	pos_rra = 0;
	while (a->value >= pivot)
	{
		pos_ra++;
		a = a->prev;
	}
	a = is_head(a);
	while (a->value >= pivot)
	{
		pos_rra++;
		a = a->next;
	}
	// printf("pivot : %d, ra: %d, rra: %d\n", pivot, pos_ra, pos_rra);
	// sleep(1);
	if (pos_ra <= pos_rra)
		return (DO_RA);
	else
		return (DO_RRA);
}

// int		no_more_pb(t_stack *a, int pivot)
// {
// 	while (a)
// 	{
// 		if (a->value < pivot)
// 			return (0);
// 		a = a->prev;
// 	}
// 	return (1);
// }

// void	len_is_size_a(t_stack **a, t_stack **b, t_info *info, int call[7])
// {
// 	int	is_ra_or_rra;

// 	is_ra_or_rra = len_is_ra_or_rra(*a, call[C_PI]);
// 	while (++call[C_I] < call[C_LEN])
// 	{
// 		// print_stack(*a, *b);
// 		if ((*a)->value >= call[C_PI])
// 		{
// 			if (no_more_pb(*a, call[C_PI]) == 0)
// 			{
// 				exec_ins(a, b, info, is_ra_or_rra);
// 				call[C_RR]++;
// 			}
// 			call[C_R]++;
// 		}
// 		else
// 		{
// 			exec_ins(a, b, info, DO_PB);
// 			call[C_P]++;
// 		}
// 	}
// }

void	div_a_to_b(t_stack **a, t_stack **b, t_info *info, int call[7])
{
	if ((*a)->value >= call[C_PI])
	{
		if (check_r_a(*a, call[C_LEN] - call[C_I], call[C_PI]) == 0)
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

void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	call[7];

	if (init_call_a(*a, info, call, len) == 0)
		return ;
	while (++call[C_I] < call[C_LEN])
	{
		if (call[C_LEN] == 2 && (*a)->value >= call[C_PI] \
		&& (*a)->prev->value < call[C_PI])
		{
			exec_ins(a, b, info, DO_SA);
			call[C_R]++;
			call[C_I]++;
		}
		div_a_to_b(a, b, info, call);
	}
	while (call[C_FL] != 1 && --call[C_RR] >= 0)
		exec_ins(a, b, info, DO_RRA);
	a_to_b(a, b, info, call[C_R]);
	b_to_a(a, b, info, call[C_P]);
}
