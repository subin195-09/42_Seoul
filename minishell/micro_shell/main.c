/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:41:17 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 14:54:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int		parse_arg(t_list **cmds, char *av)
{
	int		is_break;

	if (strcmp(";", av) == 0)
		is_break = 1;
	else
		is_break = 0;
	if (is_break && !*cmds)
		return (EXIT_SUCCESS);
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return (list_push(cmds, av);
}

int		main(int ac, char **av, char **en)
{
	t_list	*cmds;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (ac > i)
		parse_arg(&cmds, av[i++])
}
