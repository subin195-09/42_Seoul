#include "printf.h"
#include <stdio.h>

int main(void)
{
	printf("*result of  printf*\n");
	printf("hello world%d %d\n", 42, 10);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	ft_printf("hello world%d\n", 42, 10);
}
