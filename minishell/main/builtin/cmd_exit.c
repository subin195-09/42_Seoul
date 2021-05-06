/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:52:15 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_exit(t_nd *com, char ***en, char *name)
{
	int		i;

	i = 0;
	while (com->args[i])
		i++;
	printf("exit\n");
	g_ex.exit_code = 0;
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		g_ex.exit_code = 1;
		return (EXIT_SUCCESS);
	}
	else
		return (EXIT_FAILURE);
	(void)en;
	(void)name;
}
