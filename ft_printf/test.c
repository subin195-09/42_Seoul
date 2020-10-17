#include "printf.h"
#include <stdio.h>

int main(void)
{
	char *test = "%%%Qhello\n";
	printf("*result of  printf*\n");
	printf(test, -1);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	ft_printf(test, 42);
}
