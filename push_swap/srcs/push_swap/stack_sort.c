/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:43:38 by skim              #+#    #+#             */
/*   Updated: 2021/05/20 19:58:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len);
void	b_to_a(t_stack **a, t_stack **b, t_info *info, int len);

void    print_stack(t_stack *a, t_stack *b)
{
	rewind_stack(&a);
	rewind_stack(&b);
	printf("a : ");
	while (a)
	{
		printf("(%d) ", a->value);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	printf("\n");
	printf("b : ");
	while (b)
	{
		printf("(%d) ", b->value);
		if (b->next)
			b = b->next;
		else
			break ;
	}
	printf("\n");
}

int     find_min(t_stack *a, int len)
{
	int min;
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

int     find_max(t_stack *a, int len)
{
	int max;
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
		return (min);
	return ((max + min) / 2);
}

int		check_r_a(t_stack *stk, int len, int pivot)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		if (stk->value > pivot)
			return (0);
		count++;
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
	}
	return (1);
}

int		check_r_b(t_stack *stk, int len, int pivot)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (++i < len)
	{
		if (stk->value <= pivot)
			return (0);
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
		count++;
	}
	return (count);
}

int		check_asc(t_stack *stk)
{
	while (stk->prev)
	{
		if (stk->value < stk->prev->value)
			return (0);
		stk = stk->prev;
	}
	return (1);
}

void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	pivot;
	int	i;
	int	call_ra;
	int	call_rra;
	int	call_pb;
	int	check;
	int	flag;

	if (len == 1)
		return ;
	if (check_asc(*a))
		return ;
	pivot = get_pivot(*a, len);
	i = -1;
	call_ra = 0;
	call_rra = 0;
	call_pb = 0;
	check = 0;
	flag = 0;
	if (len == info->size_a)
		flag = 1;
	while (++i < len)
	{
		if (len - i == 2 && (*a)->value <= pivot && (*a)->prev->value > pivot)
		{
			printf("sa\n");
			do_sa(a, b, info);
			info->count++;
			call_ra++;
			i++;
		}
		check = check_r_a(*a, len - i, pivot);
		if ((*a)->value <= pivot)
		{
			if (check == 0)
			{
				printf("ra\n");
				do_ra(a, b, info);
				info->count++;
				call_rra++;
			}
			call_ra++;
		}
		else
		{
			printf("pb\n");
			do_pb(a, b, info);
			call_pb++;
			info->count++;
		}
	}
	i = -1;
	while (flag != 1 && ++i < call_rra)
	{
		printf("rra\n");
		do_rra(a, b, info);
		info->count++;
	}
	a_to_b(a, b, info, call_ra);
	b_to_a(a, b, info, call_pb);
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
		check = check_r_b(*b, len - i, pivot);
		if (len - i == 2 && (*b)->value > pivot && (*b)->prev->value <= pivot)
		{
			printf("sb\n");
			do_sb(a, b, info);
			info->count++;
			call_rb++;
			i++;
		}
		if ((*b)->value > pivot)
		{
			if (check == 0)
			{
				printf("rb\n");
				do_rb(a, b, info);
				call_rrb++;
				info->count++;
			}
			call_rb++;
		}
		else
		{
			printf("pa\n");
			do_pa(a, b, info);
			call_pa++;
			info->count++;
		}
	}
	i = -1;
	while(flag != 1 && ++i < call_rrb)
	{
		printf("rrb\n");
		do_rrb(a, b, info);
		info->count++;
	}
	a_to_b(a, b, info, call_pa);
	b_to_a(a, b, info, call_rb);
}

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
			printf("sa\n");
			do_sa(a, b, info);
			info->count++;
			printf("ra\n");
			do_ra(a, b, info);
			info->count++;
		}
	}
	else if ((*a)->value == min)
	{
		printf("ra\n");
		do_ra(a, b, info);
		info->count++;
		if ((*a)->value != max)
		{
			printf("sa\n");
			do_sa(a, b, info);
			info->count++;
		}
	}
	else
	{
		if ((*a)->prev->value == max)
		{
			printf("sa\n");
			do_sa(a, b, info);
			info->count++;
		}
		else
		{
			printf("rra\n");
			do_rra(a, b, info);
			info->count++;
		}
	}
}

void	less_sort(t_stack **a, t_stack **b, t_info *info)
{
	int		max;
	int		pos;
	t_stack	*anc;

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
			{
				printf("ra\n");
				do_ra(a, b, info);
				info->count++;
			}
		}
		else
		{
			while ((*a)->value != max)
			{
				printf("rra\n");
				do_rra(a, b, info);
				info->count++;
			}
		}
		printf("pb\n");
		do_pb(a, b, info);
		info->count++;
	}
	three_sort(a, b, info);
	while (info->size_b != 0)
	{
		printf("pa\n");
		do_pa(a, b, info);
		info->count++;
	}
}

void    stack_sort(t_stack **a, t_stack **b, t_info *info)
{
	// print_stack(*a, *b);
	if (info->size_a < 20)
		less_sort(a, b, info);
	else
		a_to_b(a, b, info, info->size_a);
	print_stack(*a, *b);
	printf("count : %d\n", info->count);
}
