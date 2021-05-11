/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:24 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:48:49 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(int *cpy_i, int *arg_i, char (*cpy_arg)[PATH_MAX])
{
	*arg_i = -1;
	*cpy_i = 0;
	ft_memset(cpy_arg, 0, PATH_MAX);
}

char	*env_controller(char *args, char ***en)
{
	char	cpy_arg[PATH_MAX];
	int		cpy_i;
	int		arg_i;

	env_init(&cpy_i, &arg_i, &cpy_arg);
	while (args[++arg_i])
	{
		if (args[arg_i] == '\'')
			while (args[++arg_i] != '\'')
				cpy_arg[cpy_i++] = args[arg_i];
		if (args[arg_i] == '\"')
		{
			while (args[++arg_i] != '\"')
				if (args[arg_i] == '$')
					cpy_i += env_except_qoute(args, \
					&arg_i, cpy_arg + cpy_i, en);
				else
					cpy_arg[cpy_i++] = args[arg_i];
		}
		if (!ft_strchr("\'\"$", args[arg_i]))
			cpy_arg[cpy_i++] = args[arg_i];
		if (args[arg_i] == '$')
			cpy_i += env_except_none(args, &arg_i, cpy_arg + cpy_i, en);
	}
	return (ft_strdup(cpy_arg));
}

int		token_changer(t_nd *nd, char ***en)
{
	char	*tmp;
	int		arg_count;

	while (nd)
	{
		arg_count = -1;
		while (nd->args[++arg_count])
		{
			tmp = env_controller(nd->args[arg_count], en);
			free(nd->args[arg_count]);
			nd->args[arg_count] = ft_strdup(tmp);
			free(tmp);
		}
		if (nd->sible)
			nd = nd->sible;
		else
			break ;
	}
	return (EXIT_SUCCESS);
}
