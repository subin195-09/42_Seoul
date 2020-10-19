#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%l0";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, 16);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, 16);
	printf("bytes : %d\n", byte);
}
