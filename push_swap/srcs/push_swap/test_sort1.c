/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:34:40 by skim              #+#    #+#             */
/*   Updated: 2021/05/18 12:35:39 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stack(t_stack *a, t_stack *b)
{
    rewind_stack(&a);
    rewind_stack(&b);
    printf("a : ");
    while (a)
    {
        printf("(%d) ", a->value);
        if (a->next)
            a = a->next;
        else
            break ;
    }
    printf("\n");
    printf("b : ");
    while (b)
    {
        printf("(%d) ", b->value);
        if (b->next)
            b = b->next;
        else
            break ;
    }
    printf("\n");
}

int     find_min(t_stack *a)
{
    int min;

    min = a->value;
    while (a)
    {
        if (a->value < min)
            min = a->value;
        if (a->prev)
            a = a->prev;
        else
            break ;
    }
    return (min);
}

void    worst_sort(t_stack **a, t_stack **b, t_info *info)
{
    int     next_min;

    //print_stack(*a, *b);
    next_min = info->min;
    while (*a)
    {
        if ((*a)->value == next_min)
        {
            printf("pb\n");
            do_pb(a, b, info);
            if (info->size_a > 0)
                next_min = find_min(*a);
        }
        else
        {
            printf("ra\n");
            do_ra(a, b, info);
        }
    }
    while (info->size_b > 0)
    {
        printf("pa\n");
        do_pa(a, b, info);
    }
    //print_stack(*a, *b);
}
