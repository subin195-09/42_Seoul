/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:40:18 by skim              #+#    #+#             */
/*   Updated: 2021/05/16 16:48:49 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_info(t_info *info)
{
	info->count = 0;
	info->size = 0;
}

int		main(int ac, char *av[])
{
	t_stack *stk;
	t_info	info;
	
	if (ac < 2)
		return (0);
	init_info(&info);
	stk = stack_make(av, &info);
	while (stk)
	{
		printf("%d\n", stk->value);
		stk = stk->next;
	}
	printf("size : %d\n", info.size);
	// if (check_stack(stk) < 0)
	// {
	// 	stack_free(&stk);
	// 	return (0);
	// }
	// stack_sort(&stk);
	stack_free(&stk);
	return (0);
}
