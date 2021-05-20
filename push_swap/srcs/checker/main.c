/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 20:46:27 by skim              #+#    #+#             */
/*   Updated: 2021/05/20 22:09:28 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	init_info(t_info *info)
{
	info->count = 0;
	info->size_a = 0;
	info->size_b = 0;
}

void	get_instruction(void)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
}

int		main(int ac, char *av[])
{
	// t_stack *stk_a;
	// t_stack	*stk_b;
	// t_info	info;

	// if (ac < 2)
	// 	return (0);
	// stk_a = 0;
	// stk_b = 0;
	// init_info(&info);
	// stk_a = stack_make(av, &info);
	// rewind_stack_tail(&stk_a);
	get_instruction();
	// stack_free(&stk_a);
	(void)ac;
	(void)av;
	return (0);
}
