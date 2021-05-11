#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <get_next_line.h>
#define BLT_NUM 1

char	*read_line(void)
{
	char *line;

	line = 0;
	get_next_line(0, &line);
	return (line);
}

int		cmd_exit(char **args, char **en, char *name)
{
	return (0);
}

int		cmd_echo(char **args, char **en, char *name)
{

}

char	*blt_str(int i)
{
	char	*blt_str[BLT_NUM + 1];

	blt_str[0] = "exit";
	blt_str[1] = "echo"
	blt_str[BLT_NUM] = NULL;
	return (blt_str[i]);
}

int		(*blt_func(int i))(char **args, char **en, char *name)
{
	int		(*blt_func[BLT_NUM])(char **args, char **en, char *name);

	blt_func[0] = &cmd_exit;
	blt_func[1] = &cmd_echo;
	return (blt_func[i]);
}

int		run_cmd(char *line, char **ev, char *name)
{
	int		i;

	i = -1;
	while (++i < BLT_NUM)
	{
		if (!(strcmp(line, blt_str(i))))
			return ((*blt_func(i))(&line, ev, name));
	}
	return (1);
}

int		main(int ac, char *av[], char *en[])
{
	char	*line;
	int		status = 1;

	while (status)
	{
		write(1, "minishell test> ", ft_strlen("minishell test> "));
		line = read_line();
		status = run_cmd(line, en, av[0]);
	}
	return (0);
}
