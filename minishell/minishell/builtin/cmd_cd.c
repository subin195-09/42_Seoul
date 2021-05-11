/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:08:52 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 08:57:59 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_cd_3(char ***en)
{
	char	*tmp2;
	int		rt;

	if (!find_env("OLDPWD", en))
		rt = -2;
	else
	{
		tmp2 = find_env_val("OLDPWD", en);
		rt = chdir(tmp2);
		free(tmp2);
	}
	return (rt);
}

int		cmd_cd_2(t_nd *com, char ***en)
{
	char	*tmp2;
	int		rt;

	if ((com->args[1]) && !ft_strcmp(com->args[1], "-"))
		rt = cmd_cd_3(en);
	else if (!com->args[1])
	{
		tmp2 = find_env_val("HOME", en);
		rt = chdir(tmp2);
		free(tmp2);
		if (rt < 0)
			rt = -3;
	}
	else if (com->args[1][0] == '~')
	{
		tmp2 = ft_strjoin(getenv("HOME"), com->args[1] + 1);
		rt = chdir(tmp2);
		free(tmp2);
	}
	else
		rt = chdir(com->args[1]);
	return (rt);
}

int		cd_error_msg(void)
{
	write(2, "cd: error retrieving current directory: getcwd: \
			cannot access parent directories: No such file or directory\n",\
			108);
	return (EXIT_SUCCESS);
}

void	cmd_free(char **oldpwd_val, char **old)
{
	free(*oldpwd_val);
	free(*old);
}

int		cmd_cd(t_nd *com, char ***en, char *av)
{
	char	tmp[PATH_MAX];
	char	*oldpwd_key;
	char	*oldpwd_val;
	char	*old;
	int		rt;

	rt = 0;
	if (!getcwd(tmp, PATH_MAX))
	{
		chdir(com->args[1]);
		if (!getcwd(tmp, PATH_MAX))
			return (cd_error_msg());
	}
	else
		rt = cmd_cd_2(com, en);
	if (rt < 0)
		cmd_cd_error(com, rt);
	else
	{
		rt = cmd_pwd_update(&oldpwd_key, &oldpwd_val, &old, en);
		if (rt != -1)
			cmd_free(&oldpwd_val, &old);
	}
	return (EXIT_SUCCESS);
	(void)av;
}
