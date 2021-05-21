/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 16:52:17 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 16:52:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_stack	*new_stack_tail(t_stack *pre, int value)
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

t_stack	*new_stack_head(t_stack *next, int value)
{
	t_stack	*stk;

	stk = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (!stk)
		return (0);
	stk->prev = 0;
	stk->next = next;
	stk->value = value;
	return (stk);
}

void	delete_stack(t_stack **stk)
{
	t_stack	*tmp;

	tmp = 0;
	if ((*stk)->prev)
	{
		tmp = (*stk)->prev;
		tmp->next = 0;
	}
	free(*stk);
	*stk = tmp;
}
