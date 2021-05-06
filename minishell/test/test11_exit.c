#include "test.h"

int		cmd_exit(t_nd run_com, char **en, char *name)
{
	int		i;

	i = 0;
	while (run_com->args[i])
		i++;
	printf("exit\n");
	if (i > 2)
	{
		printf("exit: too many arguments\n");
		return (1);
	}
	else
		return (0);
}
