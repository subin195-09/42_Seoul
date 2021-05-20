/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 02:14:30 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:48:57 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_ins_do_p(t_stack **a, t_stack **b, t_info *info, int i)
{
	if (i == DO_PA)
	{
		do_pa(a, b, info);
		write(1, "pa\n", 3);
		info->count++;
	}
	else if (i == DO_PB)
	{
		do_pb(a, b, info);
		write(1, "pb\n", 3);
		info->count++;
	}
}

void	exec_ins_do_s(t_stack **a, t_stack **b, t_info *info, int i)
{
	if (i == DO_SA)
	{
		do_sa(a, b, info);
		write(1, "sa\n", 3);
		info->count++;
	}
	else if (i == DO_SB)
	{
		do_sb(a, b, info);
		write(1, "sb\n", 3);
		info->count++;
	}
	else if (i == DO_SS)
	{
		do_ss(a, b, info);
		write(1, "ss\n", 3);
		info->count++;
	}
}

void	exec_ins_do_rr(t_stack **a, t_stack **b, t_info *info, int i)
{
	if (i == DO_RRA)
	{
		do_rra(a, b, info);
		write(1, "rra\n", 4);
		info->count++;
	}
	else if (i == DO_RRB)
	{
		do_rrb(a, b, info);
		write(1, "rrb\n", 4);
		info->count++;
	}
	else if (i == DO_RRR)
	{
		do_rrr(a, b, info);
		write(1, "rrr\n", 4);
		info->count++;
	}
}

void	exec_ins_do_r(t_stack **a, t_stack **b, t_info *info, int i)
{
	if (i == DO_RA)
	{
		do_ra(a, b, info);
		write(1, "ra\n", 3);
		info->count++;
	}
	else if (i == DO_RB)
	{
		do_rb(a, b, info);
		write(1, "rb\n", 3);
		info->count++;
	}
	else if (i == DO_RR)
	{
		do_rr(a, b, info);
		write(1, "rr\n", 3);
		info->count++;
	}
}

void	exec_ins(t_stack **a, t_stack **b, t_info *info, int i)
{
	if (i >= 0 && i <= 2)
		exec_ins_do_r(a, b, info, i);
	else if (i >= 3 && i <= 5)
		exec_ins_do_rr(a, b, info, i);
	else if (i >= 6 && i <= 8)
		exec_ins_do_s(a, b, info, i);
	else if (i >= 9 && i <= 10)
		exec_ins_do_p(a, b, info, i);
}
