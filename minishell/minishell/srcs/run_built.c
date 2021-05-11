/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_built.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:55 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:12:19 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "exit";
	blt_str[1] = "env";
	blt_str[2] = "pwd";
	blt_str[3] = "cd";
	blt_str[4] = "unset";
	blt_str[5] = "export";
	blt_str[6] = "echo";
	blt_str[BLT_NUM] = NULL;
	return (blt_str[i]);
}

int		(*g_blt_func(int i))(t_nd *cmd, char ***en, char *av)
{
	int		(*blt_fuck[BLT_NUM])(t_nd *cmd, char ***en, char *av);

	blt_fuck[0] = &cmd_exit;
	blt_fuck[1] = &cmd_env;
	blt_fuck[2] = &cmd_pwd;
	blt_fuck[3] = &cmd_cd;
	blt_fuck[4] = &cmd_unset;
	blt_fuck[5] = &cmd_export;
	blt_fuck[6] = &cmd_echo;
	return (blt_fuck[i]);
}

void	builtin_pipe(t_nd *cmd, char ***en, char *av, int i)
{
	int	rt;

	pipe(cmd->pipes);
	if (cmd->re.rdrt_type > 0)
		dup2(cmd->re.rdrt_fd, cmd->pipes[SIDE_IN]);
	if (cmd->re.rdrt_in_type > 0)
		dup2(cmd->re.rdrt_in_fd, cmd->pipes[SIDE_OUT]);
	g_ex.pid = fork();
	if (g_ex.pid == 0)
	{
		pipe_dup(cmd);
		if (check_red_name(cmd) > 0)
			rt = (*g_blt_func(i))(cmd, en, av);
		exit(g_ex.exit_code);
	}
	else if (g_ex.pid > 0)
	{
		waitpid(g_ex.pid, &g_ex.exit_code, WUNTRACED);
		pipe_close(cmd);
		execute_satus();
	}
	else
		write(2, "failed to fork", ft_strlen("failed to fork"));
}

int		builtin_non_pipe(t_nd *cmd, char ***en, char *av, int i)
{
	int	rt;
	int	cpy[2];

	rt = EXIT_SUCCESS;
	if (cmd->re.rdrt_type > 0)
	{
		cpy[1] = dup(STDOUT);
		dup2(cmd->re.rdrt_fd, STDOUT);
	}
	if (cmd->re.rdrt_in_type > 0)
	{
		cpy[0] = dup(STDIN);
		dup2(cmd->re.rdrt_in_fd, STDIN);
	}
	if (check_red_name(cmd) > 0)
		rt = (*g_blt_func(i))(cmd, en, av);
	if (cmd->re.rdrt_type > 0)
		make_dup(&cpy[1], STDOUT);
	if (cmd->re.rdrt_in_type > 0)
		make_dup(&cpy[0], STDIN);
	return (rt);
}

int		builtin_run(t_nd *cmd, char ***en, char *av, int i)
{
	int		rt;

	rt = EXIT_SUCCESS;
	if (cmd->type == TYPE_C_P || (cmd->prev && cmd->prev->type == TYPE_C_P))
		builtin_pipe(cmd, en, av, i);
	else
		rt = builtin_non_pipe(cmd, en, av, i);
	return (rt);
}
