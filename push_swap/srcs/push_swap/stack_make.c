/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:50:03 by skim              #+#    #+#             */
/*   Updated: 2021/05/15 21:56:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(t_stack *pre, int value)
{
	t_stack	*stk;

	stk = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stk)
		return (-1);
	stk->prev = pre;
	stk->next = 0;
	stk->value = value;
}

void	add_stack(t_stack **stk, char *av)
{
	
}

t_stack	*stack_make(char *av[])
{
	t_stack	*stk;
	int		i;

	i = 0;
	stk = 0;
	while (av[++i])
		add_stack(&stk, av[i]);
	stack_rewind(&stk);
	return (stk);
}
