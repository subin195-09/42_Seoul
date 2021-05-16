/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:50:03 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 17:56:45 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_int(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		check_dup(t_stack *stk, t_info *info)
{
	int	check[info->max - info->min + 1];
	int	i;

	i = -1;
	while (++i < info->max - info->min + 1)
		check[i] = 0;
	while (stk)
	{
		if (check[stk->value - info->min])
			return (0);
		else
			check[stk->value - info->min] = 1;
		if (stk->prev)
			stk = stk->prev;
		else
			break ;
	}
	return (1);
}

int		add_stack(t_stack **stk, char *av, t_info *info)
{
	char		**av_split;
	long long	num;
	int			i;

	av_split = ft_split(av, ' ');
	i = -1;
	while (av_split[++i])
	{
		if (!is_int(av_split[i]))
			return (0);
		num = ft_atol(av_split[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (!(*stk))
		{
			info->max = (int)num;
			info->min = (int)num;
			(*stk) = new_stack(0, (int)num);
		}
		else
		{
			(*stk)->next = new_stack(*stk, (int)num);
			*stk = (*stk)->next;
		}
		if ((int)num > info->max)
			info->max = (int)num;
		if ((int)num < info->min)
			info->min = (int)num;	
		free(av_split[i]);
		info->size++;
	}
	free(av_split);
	return (1);
}

t_stack	*stack_make(char *av[], t_info *info)
{
	t_stack	*stk;
	int		i;

	i = 0;
	stk = 0;
	while (av[++i])
	{
		if (!add_stack(&stk, av[i], info))
			exit_free(&stk);
	}
	if (!check_dup(stk, info))
		exit_free(&stk);
	rewind_stack(&stk);
	return (stk);
}
