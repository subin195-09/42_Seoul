#include "test.h"

void	pipe_dup(t_list cmd)
{
	int		err_check;

	if (cmd->type == TYPE_C_P)
		err_check = dup2(cmd->pipes[SIDE_IN], STDOUT);
	if (err_check < 0)
		return (EXIT_FAILURE);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
		err_check = dup2(cmd->prev->pipes[SIDE_OUT], STDIN);
	if (err_check < 0)
		return (EXIT_FAILURE);
}

void	pipe_close(t_list cmd)
{
	close(cmd->pipes[SIDE_IN]);
	if (cmd->sibling == NULL)
		close(cmd->pipe[SIDE_OUT]);
	if (cmd->prev && cmd->prev->type == TYPE_C_P)
		close(cmd->prev->pipe[SIDE_OUT]);
}

/*************************************/
/*			내부 함수 일 경우			 */
/*************************************/

int		execute_ps(char *run_com, char **av, char **en, char *name)
{
	pid_t	pid;

	if (cmd->type == TYPE_C_P || (cmd->prev && cmd->prev->type == TYPE_C_P))
		pipe(cmd->pipes);
	pid = fork();
	if (pid == 0)
	{
		if (cmd->type == TYPE_C_P || (cmd->prev && cmd->prev->type == TYPE_C_P))
			pipe_dup(run_com)
		if (execve(run_com, av, en) == -1)
			write(1, "permission denied", ft_strlen("permission denied"));
	}
	else if (pid > 0)
	{
		wait(&pid);
		close(run_com);
	}
	else
		write(1, "failed to fork", ft_strlen("failed to fork"));
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

/*************************************/
/*			built_in 일 경우		   */
/*************************************/

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
	int		(*bltin_ft[BLT_NUM])(char **run_com, char **en, char *av);

	bltin_ft[0] = &cmd_exit;
	bltin_ft[1] = &cmd_env;
	return (bltin_ft[i]);
}

int		builtin_run(t_list cmd, char **en, char *av, int i)
{
	pid_t	pid;

	if (cmd->type == TYPE_PIPE || (cmd->prev && cmd->prev->type == TYPE_PIPE))
	{
		pipe(cmd->pipes);
		pid = fork();
		if (pid == 0)
		{
			pipe_run(run_com);
			(*blt_func(i))(cmd->arg, en, av);
		}
		else if (pid > 0)
		{
			wait(&pid);
			pipe_close(cmd);
		}
		else
			write(1, "failed to fork", ft_strlen("failed to fork"));
	}
	else
		(*blt_func(i))(cmd->arg, en, av)
}


/*************************************/
/*			run을 분류하는 함수				  */
/*************************************/

int		run(t_list cmd, char **en, char *av)
{
	while (++i < BLT_NUM)
		if (!(strcmp(cmd->arg[0], blt_str(i))))
			builtin_run(cmd, en, av, i);
	if (access(cmd->arg[0], F_OK) != -1)
		execute_ps(run_com[0], run_com, en, av);
	else
		find_cmd(cmd->arg, en, av);
	return (rt);
}
