/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:02 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:46:52 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pipe_dup(t_nd *cmd)
{
	int		err_check;

	err_check = 0;
	if (cmd->type == TYPE_C_P)
		err_check = dup2(cmd->pipes[SIDE_IN], STDOUT);
	if (err_check < 0)
		return (EXIT_FAILURE);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
		err_check = dup2(cmd->prev->pipes[SIDE_OUT], STDIN);
	if (err_check < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	pipe_close(t_nd *cmd)
{
	close(cmd->pipes[SIDE_IN]);
	if (cmd->sible == NULL)
		close(cmd->pipes[SIDE_OUT]);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
		close(cmd->prev->pipes[SIDE_OUT]);
}

int		run_div(t_nd *cmd, char ***en, char *av)
{
	struct stat	test;
	int			i;
	int			rt;

	i = -1;
	rt = EXIT_SUCCESS;
	if (cmd->args[0])
	{
		while (++i < BLT_NUM)
			if (!(ft_strcmp(cmd->args[0], blt_str(i))))
				return (builtin_run(cmd, en, av, i));
	}
	if (stat(cmd->args[0], &test) != -1)
		execute_ps(cmd->args[0], cmd, *en, av);
	else
		find_cmd(cmd, en, av);
	return (rt);
}

int		run(t_nd *cmd, char ***en, char *av)
{
	int	rt;

	rt = EXIT_SUCCESS;
	while (cmd && rt == EXIT_SUCCESS)
	{
		rt = run_div(cmd, en, av);
		if (cmd->re.rdrt_type > 0)
			close(cmd->re.rdrt_fd);
		if (cmd->type != TYPE_C_P && cmd->re.rdrt_in_type > 0)
			close(cmd->re.rdrt_in_fd);
		if (cmd->prev && cmd->prev->type == \
		TYPE_C_P && cmd->prev->re.rdrt_in_type > 0)
			close(cmd->prev->re.rdrt_in_fd);
		if (cmd->sible)
			cmd = cmd->sible;
		else
			break ;
	}
	return (rt);
}
