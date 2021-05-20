/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:26:43 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 02:48:09 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "main.h"

# define C_R	0
# define C_RR	1
# define C_P	2

void	stack_sort(t_stack **a, t_stack **b, t_info *info);

void	less_sort(t_stack **a, t_stack **b, t_info *info);
void	a_to_b(t_stack **a, t_stack **b, t_info *info, int len);
void	b_to_a(t_stack **a, t_stack **b, t_info *info, int len);

void	exec_ins(t_stack **a, t_stack **b, t_info *info, int i);
int		check_asc(t_stack *stk);
int		get_pivot(t_stack *stk, int len);
int		find_max(t_stack *a, int len);
int		find_min(t_stack *a, int len);

#endif
