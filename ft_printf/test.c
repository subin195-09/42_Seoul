#include "printf.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	setlocale(LC_ALL, "");
	char	*test = "%*.*d\n";
	int		byte = 0;
	printf("%s\n", test);
	printf("*result of  printf*\n");
	byte = printf(test, -4, -3, 8);
	printf("bytes : %d\n", byte);
	printf("=======================\n");
	printf("*result of ft_printf*\n");
	byte = ft_printf(test, -4, -3, 8);
	byte = ft_printf("%*.*i", 4, -3, 8);
	byte = ft_printf(test, -4, -3, 8);
	byte = ft_printf("%*.*X", -4, -3, 8);
	byte = ft_printf("%*.*lld", -4, -3, 8);
	byte = ft_printf(test, -4, -3, 8);
	byte = ft_printf(test, -4, -3, 8);
	byte = ft_printf("%s", -4, -3, "kdjkfffff");
	byte = ft_printf(test, -4, -3, 8);


	printf("bytes : %d\n", byte);

	while(1)
	{
		;
	}

}
//wchar_t*
