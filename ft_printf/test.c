#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%p\n";
	int		byte = 0;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, test);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, test);
	printf("bytes : %d\n", byte);
}
