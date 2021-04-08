#include <stdio.h>

int		main(int ac, char *av[], char *en[])
{
	int i = 0;

	while (en[i])
	{
		printf("%s\n", en[i]);
		i++;
	}
}
