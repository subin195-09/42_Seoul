/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:05 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 11:44:33 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_numeric(char *str)
{
	int i;

	i = -1;
	if (str[0] == '-')
		i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}

int		cmd_exit_2(t_nd *com, char **tmp)
{
	if (!check_numeric(*tmp))
	{
		ft_putendl_fd("numeric argument required", 2);
		g_ex.exit_code = 255;
	}
	else
	{
		if (com->args[2] != 0)
		{
			ft_putendl_fd("too many arguments", 2);
			g_ex.exit_code = 1;
			free(*tmp);
			return (1);
		}
		else
			g_ex.exit_code = ft_atoi(*tmp);
	}
	free(*tmp);
	return (0);
}

int		cmd_exit(t_nd *com, char ***en, char *name)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = -1;
	if (!(com->type == TYPE_C_P || (com->prev && com->prev->type == TYPE_C_P)))
		write(2, "exit\n", ft_strlen("exit\n"));
	while (com->args[i])
		i++;
	if (i != 1)
	{
		tmp = ft_strtrim(com->args[1], SEP);
		if (cmd_exit_2(com, &tmp))
			return (EXIT_SUCCESS);
	}
	else
		g_ex.exit_code = 0;
	return (EXIT_FAILURE);
	(void)en;
	(void)name;
}
