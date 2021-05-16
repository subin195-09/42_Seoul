/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 22:12:58 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 22:36:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    do_rr(t_stack **a, t_stack **b, t_info *info)
{
    do_ra(a, b, info);
    do_rb(a, b, info);
}