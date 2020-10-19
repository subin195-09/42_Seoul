#include "printf.h"
#include <stdio.h>

int main(void)
{
	char *test = "%-10.3d%dhello\n";
	printf("%s\n", test);
	printf("*result of  printf*\n");
	printf(test, 10, 11);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	ft_printf(test, 10, 11);
}
