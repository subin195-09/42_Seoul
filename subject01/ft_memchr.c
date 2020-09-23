#include "libft.h"

void    *ft_memchr(const void *p, int value, size_t n)
{
    while(n--)
    {
        if(*(unsigned char *)p == (unsigned char)value)
            return (p);
        p++;
    }
    return (0);
}