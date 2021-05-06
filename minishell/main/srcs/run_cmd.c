/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:38:27 by spark             #+#    #+#             */
/*   Updated: 2021/05/05 23:18:23 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_cmd_2(t_nd **anc, char ***en, char *av, int *rt)
{
	while (*anc && *rt == EXIT_SUCCESS)
	{
		token_changer((*anc)->child, en);
		get_redirect((*anc)->child, *en);
		*rt = run((*anc)->child, en, av);
		if ((*anc)->sible)
			(*anc) = (*anc)->sible;
		else
			break ;
	}
}

int		run_cmd(t_nd *coms, char ***en, char *av)
{
	t_nd	*anc;
	int		rt;
	int		i;

	i = -1;
	rt = EXIT_SUCCESS;
	anc = coms;
	while (coms)
	{
		if (lexer(coms, coms->args[0]) == EXIT_FAILURE)
			return (EXIT_SUCCESS);
		if (tokenizer(coms->child) == EXIT_FAILURE)
			return (EXIT_SUCCESS);
		if (coms->sible)
			coms = coms->sible;
		else
			break ;
	}
	run_cmd_2(&anc, en, av, &rt);
	return (rt);
}
