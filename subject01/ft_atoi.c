#include "libft.h"

int     ft_atoi(const char *str)
{
    int i;
    int num;
    int sign;

    i = 0;
    num = 0;
    sign = 1;
    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    while (str[i] == '+' || str[i] == '-')
    {
        if (str[i] =='-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
        num = num * 10 + str[i++] - '0';
    return (sign * num);
}