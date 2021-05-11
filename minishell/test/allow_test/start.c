#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

int		main(int ac, char *av[])
{
	char	buf[128];
	pid_t	pid;

	while (1)
	{
		memset(buf, 0, sizeof(buf));
		read(1, buf, sizeof(buf) - 1);
		buf[strlen(buf) - 1] = 0;
		if (!strncmp(buf, "exit", strlen(buf)))
			return (-1);
		pid = fork();
		if (pid < 0)
		{
			printf("fork error\n");
			return (-1);
		}
		else if (pid == 0)
		{
			execlp(buf, buf, NULL);
			exit(0);
		}
		else
			wait(NULL);
	}
	return (0);
}
