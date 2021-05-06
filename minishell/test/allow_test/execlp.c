#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (execlp("ls", "ls", "-al" ,  NULL) == -1)
	{
		fprintf(stderr, "execve error: %s\n", strerror(errno));
		return (1);
	}
	printf("this is ls.\n");
	return (0);
}
