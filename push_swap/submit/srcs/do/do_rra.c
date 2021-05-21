/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:13:04 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:04:00 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_rra(t_stack **a, t_stack **b, t_info *info)
{
	int		tmp_value;
	t_stack	*a_head;

	if (info->size_a < 2)
		return ;
	a_head = is_head(*a);
	tmp_value = a_head->value;
	a_head->next->prev = 0;
	free(a_head);
	(*a)->next = new_stack_tail(*a, tmp_value);
	*a = (*a)->next;
	(void)b;
	(void)info;
}
