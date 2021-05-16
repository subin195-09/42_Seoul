/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:26:43 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 23:33:26 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "main.h"
# include <stdio.h>

t_stack	*stack_make(char *av[], t_info *info);

int		check_int(char *av_split, long long *num);
int		free_matrix(char ***matrix);
int		check_dup(t_stack *stk, t_info *info);

void    stack_sort(t_stack **a, t_stack **b, t_info *info);

t_stack	*new_stack_tail(t_stack *pre, int value);
t_stack *new_stack_head(t_stack *next, int value);
void	delete_stack(t_stack **stk);
t_stack	*is_head(t_stack *stk);
void	rewind_stack(t_stack **stk);
void	rewind_stack_tail(t_stack **stk);
void	stack_free(t_stack **stk);
void	exit_free(t_stack **stk);

#endif
