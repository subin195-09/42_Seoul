/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:43:38 by skim              #+#    #+#             */
/*   Updated: 2021/05/18 18:02:01 by skim             ###   ########.fr       */
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

int		get_pivot(t_stack *stk)
{
	int	min;
	int	max;

	min = find_min(stk);
	max = find_max(stk);
	printf("min : %d, max : %d\n", min, max);
	return ((max + min) / 2);
}

void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	pivot;
	int	i;
	int	call_ra;
	int	call_pb;

	if (len == 1)
		return ;
	pivot = get_pivot(*a);
	i = -1;
	call_ra = 0;
	call_pb = 0;
	printf("%d\n", len);
	sleep(1);
	while (++i < len)
	{
		if ((*a)->value > pivot)
		{
			printf("ra\n");
			do_ra(a, b, info);
			call_ra++;
		}
		else
		{
			printf("pb\n");
			do_pb(a, b, info);
			call_pb++;
		}
	}
	i = -1;
	while(++i < call_ra)
	{
		printf("rra\n");
		do_rra(a, b, info);
	}
	print_stack(*a, *b);
	a_to_b(a, b, info, call_ra);
	b_to_a(a, b, info, call_pb);
}


void	b_to_a(t_stack **a, t_stack **b, t_info *info, int len)
{
	int	pivot;
	int	i;
	int	call_rb;
	int	call_pa;

	if (len == 1)
		return ;
	pivot = get_pivot(*b);
	i = -1;
	call_rb = 0;
	call_pa = 0;
	printf("%d\n", len);
	sleep(1);
	while (++i < len)
	{
		if ((*b)->value < pivot)
		{
			printf("rb\n");
			do_rb(a, b, info);
			call_rb++;
		}
		else
		{
			printf("pa\n");
			do_pa(a, b, info);
			call_pa++;
		}
	}
	i = -1;
	while(++i < call_rb)
	{
		printf("rrb\n");
		do_rrb(a, b, info);
	}
	print_stack(*a, *b);
	a_to_b(a, b, info, call_pa);
	b_to_a(a, b, info, call_rb);
}

void    stack_sort(t_stack **a, t_stack **b, t_info *info)
{
	print_stack(*a, *b);
	a_to_b(a, b, info, info->size_a);
	print_stack(*a, *b);
}
