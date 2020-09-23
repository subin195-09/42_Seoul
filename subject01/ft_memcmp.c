#include "libft.h"

int     memcmp(const void *s1, const void *s2, size_t n)
{
    while(!s1 && !s2 && n--)
    {
        if (s1 < s2)
            return (-1);
        else if (s1 > s2)
            return (1);
        s1++;
        s2++;
    }
    return (0);
}