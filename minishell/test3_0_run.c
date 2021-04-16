/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test30_run.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:19:42 by skim              #+#    #+#             */
/*   Updated: 2021/04/16 13:25:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "exit";
	blt_str[1] = "env";
	blt_str[BLT_NUM] = NULL;
	return (blt_str[i]);
}

int		(*blt_func(int i))(char **run_com, char **en, char *av)
{
	int		(*blt_fuck[BLT_NUM])(char **run_com, char **en, char *av);

	blt_fuck[0] = &cmd_exit;
	blt_fuck[1] = &cmd_env;
	return (blt_fuck[i]);
}

int		execute_ps(char *run_com, char **av, char **en, char *name)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (execve(run_com, av, en) == -1)
			write(1, "permission denied", ft_strlen("permission denied"));
	}
	else if (pid < 0)
		write(1, "failed to fork", ft_strlen("failed to fork"));
	else
		wait(&pid);
	return (1);
}

void	find_cmd(char **run_com, char **en, char *av)
{
	char	**bash_path;
	char	temp_path[PATH_MAX];
	int		i;

	i = -1;
	bash_path = make_tok(find_env("PATH", en), ":");
	while (bash_path[++i])
	{
		ft_memset(temp_path, '\0', PATH_MAX);
		strcat(temp_path, bash_path[i]);
		if (run_com[0][0] != '/')
			strcat(temp_path, "/");
		strcat(temp_path, run_com[0]);
		if (access(temp_path, F_OK) != -1)
		{
			execute_ps(temp_path, run_com, en, av);
			break ;
		}
	}
	write(1, "error", 5);
	i = -1;
	while (bash_path[++i])
		free(bash_path[i]);
	free(bash_path);
}

/* ========================================== */
/*				추가 수정 부분					 */
/* ========================================== */

int		normal_run(t_list cmd, char **en, char *av)
{
	while (++i < BLT_NUM)
		if (!(strcmp(cmd->arg[0], blt_str(i))))
			return ((*blt_func(i))(cmd->arg, en, av));
	if (access(cmd->arg[0], F_OK) != -1)
		execute_ps(run_com[0], run_com, en, av);
	else
		find_cmd(cmd->arg, en, av);
	return (rt);
}

int		pipe_run(t_list cmd, char **en, char *av)
{
	int	error_check;

	error_check = pipe(cmd->pipes));
	if (error_check)
		return (EXIT_FAILURE);
	error_check = dup2(cmd->pipes[SIND_IN], STDOUT);
	if (error_check < 0)
		return (EXIT_FAILURE);
	normal_run(cmd, en, av);
	// close 작업해주기
	close(cmd->pipes[SIDE_IN]);
}

int		prev_pipe_run(t_list cmd, char **en, char *av)
{
	int	error_check;

	error_check = pipe(cmd->pipes));
	if (error_check)
		return (EXIT_FAILURE);
	error_check = dup2(cmd->prev->pipes[SIDE_OUT], STDIN);
	if (error_check < 0)
		return (EXIT_FAILURE);
	normal_run(cmd, en, av);
	// close 작업해주기
	close(cmd->prev->pipes[SIDE_OUT]);
	close(cmd->pipes[SIDE_IN]);
	close(cmd->pipes[SIDE_OUT]);
}

// 실행 단위로 분리된 t_list
int		run(t_list cmd, char **en, char *av)
{
	int		rt;

	// 바로 실행할 수 있도록 만들어준다.
	ready_run(cmd);
	while (cmd->sibling)
	{
		if (cmd->type == TYPE_PIPE)
			rt = pipe_run(cmd, en, av);
		else if (cmd->prev && cmd->prev->type == TYPE_PIPE)
			rt = prev_pipe_run(cmd, en, av);
		else
			rt = normal_run(cmd, en, av);
		cmd = cmd->sibling;
	}
	return (rt);
}
