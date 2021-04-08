#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

extern char **environ;

int		main(int ac, char *av[])
{
	char	**new_av;
	char	command[] = "ls";
	int		i;

	new_av = (char **)malloc(sizeof(char *) * (ac + 1));
	new_av[0] = command;

	for(i = 1; i < ac; i++)
		new_av[i] = av[i];
	new_av[i] = NULL;
	if (execve("/Users/skim/Desktop/42_Seoul/minishell", new_av, environ) == -1)
	{
		fprintf(stderr, "프로그램 실행 error: %s\n", strerror(errno));
		return (1);
	}
	printf("이곳이 이제 ls 명령어라 이 라인은 출력이 되지 않습니다.\n");
	return (0);
}
