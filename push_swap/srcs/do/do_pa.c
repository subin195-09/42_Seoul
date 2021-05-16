/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:11:40 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 23:05:12 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_pa(t_stack **a, t_stack **b, t_info *info)
{
    if (info->size_b == 0)
        return ;
    if (!(*a))
        *a = new_stack_tail(0, (*b)->value);
    else
    {
        (*a)->next = new_stack_tail(*a, (*b)->value);
        *a = (*a)->next;
    }
    delete_stack(b);
    info->size_a++;
    info->size_b--;
}