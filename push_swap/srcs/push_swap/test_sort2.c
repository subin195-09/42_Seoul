/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:57:19 by skim              #+#    #+#             */
/*   Updated: 2021/05/18 16:57:26 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int     find_min(t_stack *a)
{
	int min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		if (a->prev)
			a = a->prev;
		else
			break ;
	}
	return (min);
}

int     find_break(t_stack *a, int min, int max)
{
	int count;

	count = 0;
	while (a)
	{
		if (a->value >= min && a->value <= max)
			count++;
		a = a->prev;
	}
	return (count);
}

int     find_max(t_stack *a)
{
	int max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		if (a->prev)
			a = a->prev;
		else
			break ;
	}
	return (max);
}

int     r_or_rr_equal(t_stack *stk, int b_min, int size)
{
	int     count;

	count = 0;
	while (stk->value != b_min)
	{
		stk = stk->prev;
		count++;
	}
	if (count > (size / 2))
		return (1);
	else
		return (-1);
}

int     r_or_rr_more(t_stack *stk, int b_min, int size)
{
	int     count;

	count = 0;
	while (stk->value < b_min)
	{
		stk = stk->prev;
		count++;
	}
	if (count > (size / 2))
		return ((-1) * (size - count));
	else
		return (count);
}

void    push_b(t_stack **a, t_stack **b, t_info *info)
{
	int b_min;
	int b_max;
	int r_or_rr;

	if (*b)
	{
		b_min = find_min(*b);
		b_max = find_max(*b);
		printf("a_value : %d\n", (*a)->value);
		printf("min : %d, max : %d\n", b_min, b_max);
		if ((*a)->value < b_min) // 최소일때
		{
			r_or_rr = r_or_rr_equal(*b, b_min, info->size_b);
			while ((*b)->value != b_min)
			{
				if (r_or_rr > 0)
				{
					printf("rb\n");
					do_rb(a, b, info);
				}
				else
				{
					printf("rrb\n");
					do_rrb(a, b, info);
				}
			}
			printf("pb\n");
			do_pb(a, b, info);
		}
		else if ((*a)->value > b_max) // 최대일때
		{
			r_or_rr = r_or_rr_equal(*b, b_min, info->size_b);
			while ((*b)->value != b_min)
			{
				if (r_or_rr > 0)
				{
					printf("rb\n");
					do_rb(a, b, info);
				}
				else
				{
					printf("rrb\n");
					do_rrb(a, b, info);
				}
			}
			printf("pb\n");
			do_pb(a, b, info);
			printf("rb\n");
			do_rb(a, b, info);
		}
		else // 중간값일때
		{
			r_or_rr = r_or_rr_equal(*b, b_min, info->size_b);
			while ((*b)->value != b_min)
			{
				if (r_or_rr > 0)
				{
					printf("rb\n");
					do_rb(a, b, info);
				}
				else
				{
					printf("rrb\n");
					do_rrb(a, b, info);
				}
			}
			print_stack(*a, *b);
			r_or_rr = r_or_rr_more(*b, (*a)->value, info->size_b);
			if (r_or_rr < 0)
			{
				r_or_rr *= -1;
				while (r_or_rr)
				{
					printf("rrb\n");
					do_rrb(a, b, info);
					r_or_rr--;
				}
			}
			else
			{
				while (r_or_rr)
				{
					printf("rb\n");
					do_rb(a, b, info);
					r_or_rr--;
				}
			}
			printf("pb\n");
			do_pb(a, b, info);
		}
	}
	else
	{
		printf("pb\n");
		do_pb(a, b, info);
	}

	print_stack(*a, *b);
}

void	worst_sort_2(t_stack **a, t_stack **b, t_info *info)
{
	int chunk_size;
	int chunk_ran;
	int *chunk;
	int i;
	int r_or_rr;

	if (info->size_a < 100)
		chunk_size = 3;
	if (info->size_a >= 100)
		chunk_size = info->size_a / 20;
	chunk_ran = (info->max - info->min) / chunk_size;
	chunk = (int *)malloc(sizeof(int) * chunk_size);
	if (!chunk)
		return ;
	i = -1;
	while (++i < chunk_size)
	{
		int min = info->min + i * chunk_ran;
		int max = i + 1 == chunk_size ? info->max : info->min + (i + 1) * chunk_ran;
		int b_min = find_break(*a, min, max);
		while (*a && b_min > 0)
		{
			if ((*a)->value >= min && (*a)->value <= max)
			{
				push_b(a, b, info);
				b_min--;
			}
			else
			{
				printf("ra\n");
				do_ra(a, b, info);
			}
		}
	}
	int b_min = find_min(*b);
	r_or_rr = r_or_rr_equal(*b, b_min, info->size_b);
	while ((*b)->value != b_min)
	{
		if (r_or_rr < 0)
		{
			printf("rb\n");
			do_rb(a, b, info);
		}
		else
		{
			printf("rrb\n");
			do_rrb(a, b, info);
		}
	}
	while (info->size_b > 0)
	{
		printf("pa\n");
		do_pa(a, b, info);
	}
	print_stack(*a, *b);
}
