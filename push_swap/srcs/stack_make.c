/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_make.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:50:03 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 16:55:53 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	add_stack_first_or_not(t_stack **stk, t_info *info, int num)
{
	if (!(*stk))
	{
		info->max = num;
		info->min = num;
		(*stk) = new_stack_head(0, num);
	}
	else
	{
		(*stk)->prev = new_stack_head(*stk, num);
		*stk = (*stk)->prev;
	}
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
		if (!check_int(av_split[i], &num))
			return (free_matrix(&av_split));
		add_stack_first_or_not(stk, info, (int)num);
		if ((int)num > info->max)
			info->max = (int)num;
		if ((int)num < info->min)
			info->min = (int)num;
		free(av_split[i]);
		info->size_a++;
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
	return (stk);
}
