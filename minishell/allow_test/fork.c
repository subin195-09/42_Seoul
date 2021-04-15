#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h<

int main(int ac, char *av[])
{
	pid_t	pid;

	pid = fork();
	printf("pid : %d\n", pid);
	if (pid == 0)
		printf("child process\n");
	if (pid > 0)
	{
		printf("Wait\n");
		wait(NULL);
		printf("Exit\n");
	}
	return (0);
}
