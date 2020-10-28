#include "printf.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	setlocale(LC_ALL, "");
	char	*test = "12%n34%n*\n";
	int		type_n;
	int 	type_n2;
	int		byte = 0;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	//byte = printf(test, &type_n, &type_n2);
	//printf("%d %d\n", type_n, type_n2);
	//printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test,  &type_n, &type_n2);
	printf("%d %d\n", type_n, type_n2);
	printf("bytes : %d\n", byte);
}
//wchar_t*
