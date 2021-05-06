/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:08:52 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:51:32 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_pwd_update(char **o_key, char **o_val, char **old, char ***en)
{
	char	tmp[PATH_MAX];
	char	**new_en;
	char	*new;
	char	*new_key;

	(*o_val) = find_env_val("PWD", en);
	(*old) = ft_strjoin("OLDPWD=", (*o_val));
	free(*o_val);
	(*o_key) = find_env("OLDPWD", en);
	(*o_val) = find_env_val("OLDPWD", en);
	new = ft_strjoin("PWD=", getcwd(tmp, PATH_MAX));
	if (!*o_key)
		new_en = add_env(en, *old);
	else
		new_en = update_env(en, *old, *o_key);
	(*en) = new_en;
	new_key = find_env("PWD", en);
	new_en = update_env(en, new, new_key);
	(*en) = new_en;
	g_ex.exit_code = 0;
}

void	cmd_cd_error(t_nd *com, int rt)
{
	if (rt == -2)
		printf("minishell: %s: OLDPWD not set\n", com->args[0]);
	else if (rt == -3)
		printf("minishell: %s: HOME not set\n", com->args[0]);
	else
		printf("%s: %s: %s\n", com->args[0], com->args[1], strerror(errno));
	g_ex.exit_code = 1;
}

int		cmd_cd_2(t_nd *com, char **oldpwd_key, char **oldpwd_val, char ***en)
{
	char	*tmp2;
	int		rt;

	if ((com->args[1]) && !ft_strcmp(com->args[1], "-"))
	{
		if (!oldpwd_key)
			rt = -2;
		else
			rt = chdir(*oldpwd_val);
	}
	else if (!com->args[1])
	{
		rt = chdir(find_env_val("HOME", en));
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
		{
			printf("cd: error retrieving current directory: getcwd: \
			cannot access parent directories: No such file or directory\n");
			return (EXIT_SUCCESS);
		}
	}
	else
		rt = cmd_cd_2(com, &oldpwd_key, &oldpwd_val, en);
	if (rt < 0)
		cmd_cd_error(com, rt);
	cmd_pwd_update(&oldpwd_key, &oldpwd_val, &old, en);
	return (EXIT_SUCCESS);
	(void)av;
}
