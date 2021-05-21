/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:46:27 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 21:02:48 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdio.h> ///// 지워야함

void	print_stack(t_stack *a, t_stack *b)
{
	rewind_stack(&a);
	rewind_stack(&b);
	printf("a : ");
	while (a)
	{
		printf("(%d) ", a->value);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	printf("\n");
	printf("b : ");
	while (b)
	{
		printf("(%d) ", b->value);
		if (b->next)
			b = b->next;
		else
			break ;
	}
	printf("\n");
}

void	init_info(t_info *info)
{
	info->count = 0;
	info->size_a = 0;
	info->size_b = 0;
}

int		main(int ac, char *av[])
{
	t_stack	*stk_a;
	t_stack	*stk_b;
	t_info	info;

	if (ac < 2)
		return (0);
	stk_a = 0;
	stk_b = 0;
	init_info(&info);
	stk_a = stack_make(av, &info);
	rewind_stack_tail(&stk_a);
	get_instruction(&stk_a, &stk_b, &info);
	stack_free(&stk_a);
	return (0);
}
