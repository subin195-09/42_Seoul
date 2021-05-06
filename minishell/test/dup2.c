#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd = open("test", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IROTH | S_IRGRP);
	int	copy_out = dup(1);

	dup2(fd,1);
	close(fd);
	//printf("why?\n");
	write(1, "why?\n", 5);
	dup2(copy_out, 1);
	close(copy_out);
	//printf("hello\n");
	write(1, "hello\n", 6);
	return (0);
}
