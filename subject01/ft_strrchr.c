#include "libft.h"

char    *ft_strrchr(const char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i--;
    while (i >= 0)
    {
        if (str[i] == (unsigned char)c)
            return (&str[i]);
        i--;
    }
    return (0);
}