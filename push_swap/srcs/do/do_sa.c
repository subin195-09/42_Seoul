/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 21:50:31 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:04:23 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	do_sa(t_stack **a, t_stack **b, t_info *info)
{
	int	tmp_value;

	if (info->size_a < 2)
		return ;
	tmp_value = (*a)->value;
	(*a)->value = (*a)->prev->value;
	(*a)->prev->value = tmp_value;
	(void)b;
}
