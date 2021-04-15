/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3_run.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 18:19:42 by skim              #+#    #+#             */
/*   Updated: 2021/04/15 22:43:30 by skim             ###   ########.fr       */
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

// 각 실행단위의 명령어를 |,>,>> 단위로 구분 후 type을 지정해준다.
void	get_type(t_list *cmd)
{
	// |, >, >> 로 나뉘어진 명령어 들이 sibling으로 연결되어 있고
	// 그 중 첫번째 명령어가 cmd의 child로 연결되면 된다.

	// redirect인 경우 > 이후의 file open 후 얻은 descriptor를 fd[SIDE_IN]에 지정시켜준다.
	char	**pipe_cmds;
	int		i;

	pipe_cmds = make_tok(cmd->arg[0], "|");
	list_push(cmd, pipe_cmds);
	i = -1;
	while (cmds[++i])
	{
		if (strstr(cmds[i], ">>"))

	}
}

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

int		special_run(t_list cmd, char **en, char *av)
{
	int	error_check;

	error_check = pipe(cmd->pipes));
	if (error_check)
		return (EXIT_FAILURE);
	error_check = dup2(cmd->pipes[SIND_IN], STDOUT);
	if (error_check < 0)
		return (EXIT_FAILURE);
	error_check = dup2(cmd->prev->pipes[SIDE_OUT], STDIN);
	if (error_check < 0)
		return (EXIT_FAILURE);
	if (error_check < 0)
		return (EXIT_FAILURE);
	normal_run(cmd, en, av);
	// close 작업해주기
}

// 실행 단위로 분리된 t_list
int		run(t_list cmd, char **en, char *av)
{
	int		rt;

	// pipe, >, >> 별로 type을 지정하고 sibling 관계로 연결을 시킨다.
	get_type(cmd);
	while (cmd->sibling)
	{
		if (cmd->type == TYPE_END)
			rt = normal_run(cmd, en, av);
		else // type이 PIPE이거나, REDIRECT일 경우
			rt = special_run(cmd, en, av);
		cmd = cmd->sibling;
	}
	return (rt);
}
