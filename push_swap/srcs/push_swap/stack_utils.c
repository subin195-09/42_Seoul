/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:05:43 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 17:56:28 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(t_stack *pre, int value)
{
	t_stack	*stk;

	stk = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stk)
		return (0);
	stk->prev = pre;
	stk->next = 0;
	stk->value = value;
	return (stk);
}

void	rewind_stack(t_stack **stk)
{
	while (*stk)
	{
		if ((*stk)->prev)
			*stk = (*stk)->prev;
		else
			break;
	}
}

void	stack_free(t_stack **stk)
{
	t_stack	*tmp_stk;

	while (*stk)
	{
		if ((*stk)->next)
			tmp_stk = (*stk)->next;
		else
			tmp_stk = 0;
		free(*stk);
		(*stk) = tmp_stk;
	}
}

void	exit_free(t_stack **stk)
{
	write(STDERR, "Error\n", 6);
	rewind_stack(&stk);
	stack_free(&stk);
	exit(0);
}