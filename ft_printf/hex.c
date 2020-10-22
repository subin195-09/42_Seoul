#include <stdio.h>
#include <stdlib.h>

int		count_num_hex(int num)
{
	int count;

	count = 0;
	while (num > 0)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*change_hex(int num, int add)
{
	char	*result;
	char	hex_table[16];
	char	temp;
	int		i;

	i = 0;
	temp = '0';
	while (i < 10)
		hex_table[i++] = temp++;
	temp = 'a' + add;
	while (i < 16)
		hex_table[i++] = temp++;
	i = count_num_hex(num);
	if (!(result = malloc(i + 1)))
		return (0);
	result[i--] = '\0';
	while (num > 0)
	{
		result[i--] = hex_table[num % 16];
		num /= 16;
	}
	return (result);
}

int main(void)
{
	printf("%s\n", change_hex(15, 0));
	printf("%s\n", change_hex(15, 'A' - 'a'));
}
