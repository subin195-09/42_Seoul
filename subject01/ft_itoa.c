#include "libft.h"

char    *ft_itoa(int n)
{
    char        *result;
    long long   temp;
    int         count;
    int         sign;

    temp = n >= 0 ? n : -n;
    sign = n >= 0 ? 0 : 1;
    count = 0;
    if (n == 0)
        return (ft_strdup("0"));
    if (n > 0)
    {
        n /= 10;
        count++;
    }
    if (!(result = malloc(sign + count + 1)))
        return (0);
    if (sign)
        result[0] = '-';
    result[sign + count--] = '\0';
    while(temp > 0)
    {
        result[sign + count--] = temp % 10 + '0';
        temp /= 10;
    }
    return (result);
}