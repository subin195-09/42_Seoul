/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:27:33 by skim              #+#    #+#             */
/*   Updated: 2021/05/25 15:13:28 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define STDERR 2

# define DO_RA	0
# define DO_RB	1
# define DO_RR	2
# define DO_RRA	3
# define DO_RRB	4
# define DO_RRR	5
# define DO_SA	6
# define DO_SB	7
# define DO_SS	8
# define DO_PA	9
# define DO_PB	10

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

void	do_sa(t_stack **a, t_stack **b, t_info *info);
void	do_sb(t_stack **a, t_stack **b, t_info *info);
void	do_ss(t_stack **a, t_stack **b, t_info *info);

void	do_pa(t_stack **a, t_stack **b, t_info *info);
void	do_pb(t_stack **a, t_stack **b, t_info *info);

void	do_ra(t_stack **a, t_stack **b, t_info *info);
void	do_rb(t_stack **a, t_stack **b, t_info *info);
void	do_rr(t_stack **a, t_stack **b, t_info *info);

void	do_rra(t_stack **a, t_stack **b, t_info *info);
void	do_rrb(t_stack **a, t_stack **b, t_info *info);
void	do_rrr(t_stack **a, t_stack **b, t_info *info);

int		check_int(char *av_split, long long *num);
int		free_matrix(char ***matrix);
int		check_dup(t_stack *stk, t_info *info);
t_stack	*stack_make(char *av[], t_info *info);

t_stack	*new_stack_tail(t_stack *pre, int value);
t_stack	*new_stack_head(t_stack *next, int value);
void	delete_stack(t_stack **stk);
t_stack	*is_head(t_stack *stk);
void	rewind_stack(t_stack **stk);
void	rewind_stack_tail(t_stack **stk);
void	stack_free(t_stack **stk);
void	exit_free(t_stack **stk);

#endif
