/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 18:14:10 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 21:19:29 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("size : %zu\n", size);
	while (stk)
	{
		printf("%d, %zu\n", stk->value, (size_t)((long)(stk->value) - (long)info->min));
		if (check[(size_t)((long)(stk->value) - (long)info->min)])
			return (0);
		else
			check[(size_t)((long)(stk->value) - (long)info->min)] = 1;
		if (stk->prev)
			stk = stk->prev;
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
		if (stk->prev)
		{
			anc = stk->prev;
			while (anc)
			{
				if (anc->value == stk->value)
					return (0);
				if (anc->prev)
					anc = anc->prev;
				else
					break ;
			}
			stk = stk->prev;
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
