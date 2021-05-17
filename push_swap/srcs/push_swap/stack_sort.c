/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:43:38 by skim              #+#    #+#             */
/*   Updated: 2021/05/17 20:57:59 by skim             ###   ########.fr       */
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

void    test_do(t_stack **a, t_stack **b, t_info *info)
{
    printf("origin\n");
    print_stack(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stack(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stack(*a, *b);

    printf("\npa\n");
    do_pa(a, b, info);
    print_stack(*a, *b);

    printf("\nsa\n");
    do_sa(a, b, info);
    print_stack(*a, *b);

    printf("\npb\n");
    do_pb(a, b, info);
    print_stack(*a, *b);

    printf("\nsb\n");
    do_sb(a, b, info);
    print_stack(*a, *b);

    printf("\nss\n");
    do_ss(a, b, info);
    print_stack(*a, *b);

    printf("\nra\n");
    do_ra(a, b, info);
    print_stack(*a, *b);

    printf("\nrb\n");
    do_rb(a, b, info);
    print_stack(*a, *b);

    printf("\nrr\n");
    do_rr(a, b, info);
    print_stack(*a, *b);

    printf("\nrra\n");
    do_rra(a, b, info);
    print_stack(*a, *b);

    printf("\nrrb\n");
    do_rrb(a, b, info);
    print_stack(*a, *b);

    printf("\nrrr\n");
    do_rrr(a, b, info);
    print_stack(*a, *b);
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

int     find_break(t_stack *a, int min, int max)
{
    int count;

    count = 0;
    while (a)
    {
        if (a->value >= min && a->value <= max)
            count++;
        a = a->prev;
    }
    return (count);
}

int     find_max(t_stack *a)
{
    int max;

    max = a->value;
    while (a)
    {
        if (a->value > max)
            max = a->value;
        if (a->prev)
            a = a->prev;
        else
            break ;
    }
    return (max);
}

void    push_b(t_stack **a, t_stack **b, t_info *info)
{
    int b_min;
    int b_max;

    if (*b)
    {
        b_min = find_min(*b);
        b_max = find_max(*b);
        printf("a_value : %d\n", (*a)->value);
        printf("min : %d, max : %d\n", b_min, b_max);
        if ((*a)->value < b_min)
        {
            while ((*b)->value != b_min)
            {
                printf("rb\n");
                do_rb(a, b, info);
            }
            printf("pb\n");
            do_pb(a, b, info);
        }
        else if ((*a)->value > b_max)
        {
            while ((*b)->value != b_min)
            {
                printf("rb\n");
                do_rb(a, b, info);
            }
            printf("pb\n");
            do_pb(a, b, info);
            printf("rb\n");
            do_rb(a, b, info);
        }
        else
        {
            while ((*b)->value < (*a)->value)
            {
                printf("rb\n");
                do_rb(a, b, info);
            }
            printf("pb\n");
            do_pb(a, b, info);
            while ((*b)->value != b_min)
            {
                printf("rb\n");
                do_rb(a, b, info);
            }
        }
    }
    else
    {
        printf("pb\n");
        do_pb(a, b, info);
    }

    print_stack(*a, *b);
}

void    stack_sort(t_stack **a, t_stack **b, t_info *info)
{
    int chunk_size;
    int chunk_ran;
    int *chunk;
    int i;

    if (info->size_a < 100)
        chunk_size = 3;
    if (info->size_a >= 100)
        chunk_size = info->size_a / 20;
    chunk_ran = (info->max - info->min) / chunk_size;
    chunk = (int *)malloc(sizeof(int) * chunk_size);
    if (!chunk)
        return ;
    i = -1;
    while (++i < chunk_size)
    {
        int min = info->min + i * chunk_ran;
        int max = i + 1 == chunk_size ? info->max : info->min + (i + 1) * chunk_ran;
        int brk = find_break(*a, min, max);
        while (*a && brk > 0)
        {
            if ((*a)->value >= min && (*a)->value <= max)
            {
                push_b(a, b, info);
                brk--;
            }
            else
            {
                printf("ra\n");
                do_ra(a, b, info);
            }
        }
    }
    while (info->size_b > 0)
    {
        printf("pa\n");
        do_pa(a, b, info);
    }
    print_stack(*a, *b);
}
