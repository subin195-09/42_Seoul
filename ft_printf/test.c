#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%.3s\n";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, "hello");
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, "hello");
	printf("bytes : %d\n", byte);
}
