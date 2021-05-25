/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 01:48:57 by skim              #+#    #+#             */
/*   Updated: 2021/05/21 21:16:56 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ins_str(int i)
{
	char	*ins_str[12];

	ins_str[DO_RA] = "ra";
	ins_str[DO_RB] = "rb";
	ins_str[DO_RR] = "rr";
	ins_str[DO_RRA] = "rra";
	ins_str[DO_RRB] = "rrb";
	ins_str[DO_RRR] = "rrr";
	ins_str[DO_SA] = "sa";
	ins_str[DO_SB] = "sb";
	ins_str[DO_SS] = "ss";
	ins_str[DO_PA] = "pa";
	ins_str[DO_PB] = "pb";
	ins_str[11] = 0;
	return (ins_str[i]);
}

void	(*ins_fun(int i))(t_stack **a, t_stack **b, t_info *info)
{
	void	(*ins_fun[11])(t_stack **a, t_stack **b, t_info *info);

	ins_fun[DO_RA] = &do_ra;
	ins_fun[DO_RB] = &do_rb;
	ins_fun[DO_RR] = &do_rr;
	ins_fun[DO_RRA] = &do_rra;
	ins_fun[DO_RRB] = &do_rrb;
	ins_fun[DO_RRR] = &do_rrr;
	ins_fun[DO_SA] = &do_sa;
	ins_fun[DO_SB] = &do_sb;
	ins_fun[DO_SS] = &do_ss;
	ins_fun[DO_PA] = &do_pa;
	ins_fun[DO_PB] = &do_pb;
	return (ins_fun[i]);
}

int		check_asc(t_stack *stk)
{
	while (stk && stk->prev)
	{
		if (stk->value > stk->prev->value)
			return (0);
		stk = stk->prev;
	}
	return (1);
}

int		find_ins(t_stack **a, t_stack **b, t_info *info, char **line)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		if (!(ft_strcmp(*line, ins_str(i))))
		{
			ins_fun(i)(a, b, info);
			break ;
		}
	}
	if (i == 11)
	{
		free(*line);
		return (write(2, "Error\n", 6));
	}
	return (0);
}

int	get_instruction(t_stack **a, t_stack **b, t_info *info)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (find_ins(a, b, info, &line) > 0)
			return (0);
		free(line);
		line = 0;
	}
	if (line)
		free(line);
	if (info->size_b == 0 && check_asc(*a))
		return (write(1, "OK\n", 3));
	else
		return (write(1, "KO\n", 3));
}
