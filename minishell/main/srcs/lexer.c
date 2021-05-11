/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:50 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 17:37:42 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		tokenizer(t_nd *nd)
{
	char	*tmp;
	char	**before_arg;
	int		i;

	if (synerror_redirect(nd->args[0]))
		return (EXIT_FAILURE);
	while (nd)
	{
		tmp = ft_strdup(nd->args[0]);
		free(nd->args[0]);
		free(nd->args);
		before_arg = split_quote(tmp, SEP);
		nd->args = split_redirect(before_arg);
		free(tmp);
		i = 0;
		while (before_arg[i])
			free(before_arg[i++]);
		free(before_arg);
		if (nd->sible)
			nd = nd->sible;
		else
			break ;
	}
	return (EXIT_SUCCESS);
}

void	lexer_2(t_nd **anc, char *tok_pipe)
{
	(*anc)->sible = new_nd(tok_pipe);
	(*anc)->sible->prev = (*anc);
	*anc = (*anc)->sible;
}

int		lexer(t_nd *anc, char *args)
{
	char	**tok_pipe;
	int		i;

	if (synerror_checker(args, '|') < 0)
		return (EXIT_FAILURE);
	tok_pipe = split_quote(args, "|");
	i = -1;
	while (tok_pipe[++i])
	{
		if (i == 0)
		{
			anc->child = new_nd(tok_pipe[i]);
			anc = anc->child;
		}
		else
			lexer_2(&anc, tok_pipe[i]);
		anc->type = TYPE_C_P;
		free(tok_pipe[i]);
	}
	anc->type = TYPE_NONE;
	free(tok_pipe);
	return (EXIT_SUCCESS);
}
