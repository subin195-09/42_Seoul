/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:10 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 20:43:39 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		check_dup_flag(t_stack *stk, t_info *info)
{
	int		*check;
	size_t	size;
	int		i;

	i = -1;
	size = (long)info->max - (long)info->min + 1;
	check = ft_calloc(size, sizeof(int));
	if (!check)
		return (0);
	while (stk)
	{
		if (check[(size_t)((long)(stk->value) - (long)info->min)])
			return (0);
		else
			check[(size_t)((long)(stk->value) - (long)info->min)] = 1;
		if (stk->next)
			stk = stk->next;
		else
			break ;
	}
	return (1);
}

int		check_dup_rot(t_stack *stk)
{
	t_stack *anc;

	while (stk)
	{
		if (stk->next)
		{
			anc = stk->next;
			while (anc)
			{
				if (anc->value == stk->value)
					return (0);
				if (anc->next)
					anc = anc->next;
				else
					break ;
			}
			stk = stk->next;
		}
		else
			break ;
	}
	return (1);
}

int		check_dup(t_stack *stk, t_info *info)
{
	int	rt;

	if (info->size_a > 1000)
		rt = check_dup_flag(stk, info);
	else
		rt = check_dup_rot(stk);
	return (rt);
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
