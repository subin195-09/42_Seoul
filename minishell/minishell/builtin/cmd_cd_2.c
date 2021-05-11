/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:08:52 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 08:44:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_pwd_update(char **o_key, char **o_val, char **old, char ***en)
{
	char	tmp[PATH_MAX];
	char	**new_en;
	char	*new;
	char	*new_key;

	(*o_val) = find_env_val("PWD", en);
	if (!(*o_val))
		return (-1);
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
	free(new);
	g_ex.exit_code = 0;
	return (0);
}

void	cmd_cd_error(t_nd *com, int rt)
{
	g_ex.exit_code = 1;
	if (rt == -2)
		write(2, "OLDPWD not set\n", ft_strlen("OLDPWD not set\n"));
	else if (rt == -3)
		write(2, "HOME not set\n", ft_strlen("HOME not set\n"));
	else
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write(2, "\n", 1);
	}
	(void)com;
}
