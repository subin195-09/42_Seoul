/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:26:43 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 17:17:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "main.h"
# include <stdio.h>

t_stack	*stack_make(char *av[], t_info *info);

t_stack	*new_stack(t_stack *pre, int value);
void	rewind_stack(t_stack **stk);
void	stack_free(t_stack **stk);

#endif
