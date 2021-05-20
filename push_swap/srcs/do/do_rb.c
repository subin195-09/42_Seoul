/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:12:51 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:03:43 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_rb(t_stack **a, t_stack **b, t_info *info)
{
	int		tmp_value;
	t_stack *b_head;

	if (info->size_b < 2)
		return ;
	tmp_value = (*b)->value;
	b_head = is_head(*b);
	b_head->prev = new_stack_head(b_head, tmp_value);
	delete_stack(b);
	(void)a;
	(void)info;
}
