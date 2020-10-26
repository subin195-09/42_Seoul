#include "printf.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	setlocale(LC_ALL, "");
	char	*test = "%#lo\n";
	int		byte = 0;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, 32);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, 32);
	printf("bytes : %d\n", byte);
}
