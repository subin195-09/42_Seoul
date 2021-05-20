/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:12:44 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:03:16 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_ra(t_stack **a, t_stack **b, t_info *info)
{
	int		tmp_value;
	t_stack	*a_head;

	if (info->size_a < 2)
		return ;
	tmp_value = (*a)->value;
	a_head = is_head(*a);
	a_head->prev = new_stack_head(a_head, tmp_value);
	delete_stack(a);
	(void)b;
	(void)info;
}
