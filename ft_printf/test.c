#include "printf.h"
#include <stdio.h>

int main(void)
{
	char *test = "%-10.3dhello\n";
	printf("%s\n", test);
	printf("*result of  printf*\n");
	printf(test, -12345);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	ft_printf(test, -12345);
}
