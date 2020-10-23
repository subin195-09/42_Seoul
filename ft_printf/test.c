#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%u\n";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, 4294967295u);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, 4294967295u);
	printf("bytes : %d\n", byte);
}
