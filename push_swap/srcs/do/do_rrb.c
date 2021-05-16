/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:13:10 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 23:21:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_rrb(t_stack **a, t_stack **b, t_info *info)
{
    int     tmp_value;
    t_stack *b_head;

    if (info->size_b < 2)
        return ;
    b_head = is_head(*b);
    tmp_value = b_head->value;
    b_head->next->prev = 0;
    free(b_head);
    (*b)->next = new_stack_tail(*b, tmp_value);
    *b = (*b)->next;
    (void)a;
    (void)info;
}