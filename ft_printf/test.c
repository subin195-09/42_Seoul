#include "printf.h"
#include <stdio.h>

int main(void)
{
	char	*test = "%010s%c%+10dhello\n";
	int		byte;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, "abc", '1', 10);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, "abc", '1', 10);
	printf("bytes : %d\n", byte);
}
