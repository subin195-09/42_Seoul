#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%010shello\n";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, "a");
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of fr_printf*\n");
	byte = ft_printf(test, "a");
	printf("bytes : %d\n", byte);
}
