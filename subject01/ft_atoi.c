int     ft_atoi(char *str)
{
    int num;
    int sign;

    num = 0;
    sign = 1;
    while ((*str >= 9 && *str <= 13) || *str == ' ')
        str++;
    while (*str == '+' || *str == '-')
    {
        if (*str =='-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        num = num * 10 + *str - '0';
        str++;
    }
    return (sign * num);
}