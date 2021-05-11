#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int		main()
{
	int	fd[2];
	pid_t	childpid;

	pipe(fd);
	if((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	if(childpid == 0)
	{
		dup2(fd[1], 1);
		printf("hello\n");
		close(fd[0]);
	}
	else
	{
		char buf[100];
		read(fd[0], buf, sizeof(buf));
		printf("test : %s", buf);
		close(fd[1]);
	}
}
