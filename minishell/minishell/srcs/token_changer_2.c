/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_changer_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:22 by spark             #+#    #+#             */
/*   Updated: 2021/05/09 21:59:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_changer_exit_code(int *arg_i, char *cpy_arg)
{
	char	*key_val;
	int		cpy_i;

	(*arg_i)++;
	key_val = ft_itoa(g_ex.exit_code);
	ft_strcat(cpy_arg, key_val);
	cpy_i = ft_strlen(key_val);
	free(key_val);
	return (cpy_i);
}

int	env_changer_dollor(char *args, int *arg_i, char *cpy_arg)
{
	if (!args[(*arg_i) + 1])
	{
		ft_strcat(cpy_arg, "$");
		return (-1);
	}
	return (1);
}

int	env_changer(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	char	key_tmp[PATH_MAX];
	char	*key_val;
	int		k;
	int		cpy_i;

	ft_memset(key_tmp, 0, PATH_MAX);
	cpy_i = 0;
	k = 0;
	if (env_changer_dollor(args, arg_i, cpy_arg) < 0)
		return (1);
	if (args[(*arg_i) + 1] == '?')
		return (env_changer_exit_code(arg_i, cpy_arg));
	while (!ft_strchr(" \\\t\n\r\a\"\'$/", args[++(*arg_i)]))
		key_tmp[k++] = args[(*arg_i)];
	if (args[(*arg_i)])
		(*arg_i)--;
	key_val = find_env_val(key_tmp, en);
	if (key_val)
	{
		ft_strcat(cpy_arg, key_val);
		cpy_i = ft_strlen(key_val);
		free(key_val);
	}
	return (cpy_i);
}

int	env_except_qoute(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	if ((args[(*arg_i) + 1] == '\'') || (args[(*arg_i) + 1] == '\"')
	|| (args[(*arg_i) + 1] == '$'))
	{
		ft_strcat(cpy_arg, "$");
		return (1);
	}
	else
		return (env_changer(args, arg_i, cpy_arg, en));
}

int	env_except_none(char *args, int *arg_i, char *cpy_arg, char ***en)
{
	if ((args[(*arg_i) + 1] == '\'') || (args[(*arg_i) + 1] == '\"')\
	|| (args[(*arg_i) + 1] == '$'))
		return (0);
	else
		return (env_changer(args, arg_i, cpy_arg, en));
}
