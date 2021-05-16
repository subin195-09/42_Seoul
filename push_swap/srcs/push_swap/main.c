/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:40:18 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 22:50:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *info)
{
	info->count = 0;
	info->size_a = 0;
	info->size_b = 0;
}

int		main(int ac, char *av[])
{
	t_stack *stk_a;
	t_stack	*stk_b;
	t_info	info;
	
	if (ac < 2)
		return (0);
	stk_a = 0;
	stk_b = 0;
	init_info(&info);
	stk_a = stack_make(av, &info);
	printf("size : %d, min : %d, max : %d\n", info.size_a, info.min, info.max);
	stack_sort(&stk_a, &stk_b, &info);
	stack_free(&stk_a);
	return (0);
}
