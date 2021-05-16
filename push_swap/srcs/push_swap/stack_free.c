/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:45:47 by skim              #+#    #+#             */
/*   Updated: 2021/05/15 21:49:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
