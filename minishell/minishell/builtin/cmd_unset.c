/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:14 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 14:04:30 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_arg(char *str)
{
	if ((!(ft_isalpha(str[0]) || (str[0] == '_'))) || ft_strchr(str, '='))
	{
		g_ex.exit_code = -1;
		write(2, "not a valid identifier\n", \
		ft_strlen("not a valid identifier\n"));
		return (0);
	}
	return (1);
}

int	cmd_unset(t_nd *com, char ***en, char *av)
{
	char	*tmp;
	char	**new_en;
	int		i;

	if (!com->args[1] || !com->args[1][0])
	{
		g_ex.exit_code = 0;
		return (EXIT_SUCCESS);
	}
	i = 0;
	while (com->args[++i])
	{
		tmp = find_env(com->args[i], en);
		if (check_arg(com->args[i]) && tmp)
		{
			new_en = delete_env(en, tmp);
			(*en) = new_en;
		}
	}
	if (g_ex.exit_code < 0)
		g_ex.exit_code = 1;
	else
		g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
	(void)av;
}
