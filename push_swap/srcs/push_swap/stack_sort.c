/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:43:38 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 23:11:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_stak(t_stack *a, t_stack *b)
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

void    stack_sort(t_stack **a, t_stack **b, t_info *info)
{
    printf("origin\n");
    print_stak(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stak(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stak(*a, *b);

    printf("\npa\n");
    do_pa(a, b, info);
    print_stak(*a, *b);

    printf("\nsa\n");
    do_sa(a, b, info);
    print_stak(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stak(*a, *b);

    printf("\nsb\n");
    do_sb(a, b, info);
    print_stak(*a, *b);

    printf("\nss\n");
    do_ss(a, b, info);
    print_stak(*a, *b);

    printf("\nra\n");
    do_ra(a, b, info);
    print_stak(*a, *b);

    printf("\nrb\n");
    do_rb(a, b, info);
    print_stak(*a, *b);

    printf("\nrr\n");
    do_rr(a, b, info);
    print_stak(*a, *b);

    printf("\nrra\n");
    do_rra(a, b, info);
    print_stak(*a, *b);

    printf("\nrrb\n");
    do_rrb(a, b, info);
    print_stak(*a, *b);
    
    printf("\nrrr\n");
    do_rrr(a, b, info);
    print_stak(*a, *b);
}