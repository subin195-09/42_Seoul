/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 17:05:43 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 16:52:39 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	rewind_stack(t_stack **stk)
{
	while (*stk)
	{
		if ((*stk)->prev)
			*stk = (*stk)->prev;
		else
			break ;
	}
}

void	rewind_stack_tail(t_stack **stk)
{
	while (*stk)
	{
		if ((*stk)->next)
			*stk = (*stk)->next;
		else
			break ;
	}
}

t_stack	*is_head(t_stack *stk)
{
	while (stk)
	{
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
	}
	return (stk);
}

void	stack_free(t_stack **stk)
{
	t_stack	*tmp_stk;

	while (*stk)
	{
		if ((*stk)->prev)
			tmp_stk = (*stk)->prev;
		else
			tmp_stk = 0;
		free(*stk);
		(*stk) = tmp_stk;
	}
}

void	exit_free(t_stack **stk)
{
	write(STDERR, "Error\n", 6);
	rewind_stack(stk);
	stack_free(stk);
	exit(0);
}
