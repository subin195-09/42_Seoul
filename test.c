#include <stdio.h>

int main(void)
{
	int num;

	num = printf("%+9f\n", 0.123456);
	printf("%d\n", num);
}
