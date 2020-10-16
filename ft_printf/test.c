#include "printf.h"
#include <stdio.h>

int main(void)
{
	char *test = "%013.15dhello\n";
	printf("*result of  printf*\n");
	printf(test, 42);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	ft_printf(test, 42);
}
