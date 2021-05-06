# include "libft.h"
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <sys/stat.h>


#define SIDE_OUT	0
#define SIDE_IN		1

# define STDOUT		1
# define STDIN		0

int		main(void)
{
	pid_t pid;
	int		fd_file;
	int		fd[2];
	char	buff[1024];

	//pipe(fd);
	fd_file = open("test1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
	//dup2(fd_file, fd[SIDE_IN]);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		//dup2(fd[SIDE_IN], STDOUT);
		dup2(fd_file, STDOUT);
		write(STDOUT, ":)", 2);
		//close(fd[SIDE_OUT]);
		//close(fd_file);
	}
	else
	{
		wait(0);
		//read(fd[SIDE_OUT], buff, 5);
		//printf("\n>> %s\n", buff);
		//close(fd[SIDE_IN]);
	}
	
	return (0);	
}