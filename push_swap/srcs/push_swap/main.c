/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 21:40:18 by skim              #+#    #+#             */
/*   Updated: 2021/05/15 21:51:24 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char *av[])
{
	t_stack *stk;

	if (ac < 2)
		return (0);
	stk = stack_make(av);
	if (check_stack(stk) < 0)
	{
		stack_free(&stk);
		return (0);
	}
	stack_sort(&stk);
	stack_free(&stk);
	return (0);
}
