/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:12 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:55:21 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_pwd(t_nd *com, char ***en, char *av)
{
	char	*pwd;

	pwd = find_env_val("PWD", en);
	printf("%s\n", pwd);
	free(pwd);
	g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
	(void)av;
	(void)com;
}
