/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_changer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:24 by spark             #+#    #+#             */
/*   Updated: 2021/05/08 17:45:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_init(int *cpy_i, int *arg_i, char (*cpy_arg)[PATH_MAX], int *bs_f)
{
	*arg_i = -1;
	*cpy_i = 0;
	*bs_f = 1;
	ft_memset(cpy_arg, 0, PATH_MAX);
}

void	env_qq(char *args, char *cpy_arg, int arg[2], char ***en)
{
	int	bs_f;

	bs_f = 1;
	while (bs_f > 0 && args[++arg[0]] != '"')
	{
		if (bs_f > 0 && args[arg[0]] == '\\')
		{
			bs_f = -1;
			if (!ft_strchr("\\\"$`", args[arg[0] + 1]))
				cpy_arg[arg[1]++] = args[arg[0]];
			arg[0]++;
		}
		if (bs_f > 0 && args[arg[0]] == '$')
			arg[1] += env_except_qoute(args, &arg[0], cpy_arg + arg[1], en);
		else if (bs_f < 0 && args[arg[0]] == '\\')
			cpy_arg[arg[1]++] = args[arg[0]];
		else
			cpy_arg[arg[1]++] = args[arg[0]];
		bs_f = 1;
	}
}

char	*env_controller(char *args, char ***en)
{
	char	cpy_arg[PATH_MAX];
	int		arg[2];
	int		bs_f;

	env_init(&arg[1], &arg[0], &cpy_arg, &bs_f);
	while (args[++arg[0]])
	{
		if (bs_f > 0 && args[arg[0]] == '\\')
		{
			bs_f *= -1;
			arg[0]++;
		}
		if (bs_f > 0 && args[arg[0]] == '\'')
			while (args[++arg[0]] != '\'')
				cpy_arg[arg[1]++] = args[arg[0]];
		if (bs_f > 0 && args[arg[0]] == '"')
			env_qq(args, cpy_arg, arg, en);
		if (bs_f < 0 || !ft_strchr("\'\"$", args[arg[0]]))
			cpy_arg[arg[1]++] = args[arg[0]];
		if (bs_f > 0 && args[arg[0]] == '$')
			arg[1] += env_except_none(args, &arg[0], cpy_arg + arg[1], en);
		bs_f = 1;
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
