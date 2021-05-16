/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:12:36 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 23:05:16 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_pb(t_stack **a, t_stack **b, t_info *info)
{
    if (info->size_a == 0)
        return ;
    if (!(*b))
        *b = new_stack_tail(0, (*a)->value);
    else
    {
        (*b)->next = new_stack_tail(*b, (*a)->value);
        *b = (*b)->next;
    }
    delete_stack(a);
    info->size_a--;
    info->size_b++;
}