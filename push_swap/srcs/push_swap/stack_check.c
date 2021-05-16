/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:10 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 18:15:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int		free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free((*matrix));
	return (0);
}

int		is_int(char *str)
{
	int	i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}

int		check_int(char *av_split, long long *num)
{
	if (!is_int(av_split))
		return (0);
	(*num) = ft_atol(av_split);
	if (*num > INT_MAX || *num < INT_MIN)
		return (0);
	return (1);
}
