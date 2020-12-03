#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int		r;
	char	*line;

	//while (1)
	//{
	//}
	line = NULL;
	printf("===================================================\n");
	while ((r = get_next_line(&line)) > 0)
	{	
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	printf("===================================================\n");
}
