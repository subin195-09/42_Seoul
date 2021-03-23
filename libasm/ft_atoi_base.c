#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int		get_size(int change_int, int base_len)
{
	int size = 0;
	while (change_int)
	{
		change_int /= base_len;
		size++;
	}
	return (size);
}

char	*ft_atoi_base(char *str, char *base)
{
	int		base_len = strlen(base);
	int		change_int;
	int		i = 0;
	int		sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	change_int = 0;
	while (str[i])
	{
		change_int = change_int * 10 + str[i] - '0';
		i++;
	}
	int		size = get_size(change_int, base_len);
	if (sign < 0)
		size++;
	char 	*ret = malloc(sizeof(char) * (size + 1));
	i = size;
	ret[i--] = 0;
	while (change_int != 0)
	{
		ret[i] = base[change_int % base_len];
		change_int /= base_len;
		i--;
	}
	if (sign < 0)
		ret[i] = '-';
	return (ret);
}

int main(void)
{
	printf("%s\n", ft_atoi_base("13", "0123456789abcdef"));
}
