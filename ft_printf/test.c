#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%%\n";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, 5);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, 5);
	printf("bytes : %d\n", byte);
}
