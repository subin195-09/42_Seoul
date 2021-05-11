/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:08:56 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:51:58 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		check_n(char *str)
{
	int	j;

	j = 0;
	if (str[j] == '-')
	{
		j++;
		while (str[j] == 'n')
			j++;
		if (!(j == 1 || str[j]))
			return (-1);
	}
	return (1);
}

int		cmd_echo_2(t_nd *com)
{
	int		i;
	int		j;
	int		is_n;
	int		n_tmp;

	j = 0;
	i = 1;
	is_n = 1;
	n_tmp = check_n(com->args[i]);
	while (n_tmp < 0 && com->args[i])
	{
		i++;
		if (com->args[i])
			n_tmp = check_n(com->args[i]);
		is_n = -1;
	}
	while (com->args[i])
	{
		write(1, com->args[i], ft_strlen(com->args[i]));
		if (com->args[i + 1])
			write(1, " ", 1);
		i++;
	}
	return (is_n);
}

int		cmd_echo(t_nd *com, char ***en, char *av)
{
	int		is_n;

	if (!com->args[1])
	{
		printf("\n");
		return (EXIT_SUCCESS);
	}
	is_n = cmd_echo_2(com);
	if (is_n != -1)
		printf("\n");
	g_ex.exit_code = 0;
	return (EXIT_SUCCESS);
	(void)en;
	(void)av;
}
