/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:27:33 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 22:49:36 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define STDERR 2
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				value;
}				t_stack;

typedef struct	s_info
{
	int			count;
	int			size_a;
	int			size_b;
	int			max;
	int			min;
}				t_info;

void    do_sa(t_stack **a, t_stack **b, t_info *info);
void    do_sb(t_stack **a, t_stack **b, t_info *info);
void    do_ss(t_stack **a, t_stack **b, t_info *info);

void    do_pa(t_stack **a, t_stack **b, t_info *info);
void    do_pb(t_stack **a, t_stack **b, t_info *info);

void    do_ra(t_stack **a, t_stack **b, t_info *info);
void    do_rb(t_stack **a, t_stack **b, t_info *info);
void    do_rr(t_stack **a, t_stack **b, t_info *info);

void    do_rra(t_stack **a, t_stack **b, t_info *info);
void    do_rrb(t_stack **a, t_stack **b, t_info *info);
void    do_rrr(t_stack **a, t_stack **b, t_info *info);


#endif
