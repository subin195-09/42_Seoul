#include "libft.h"

void    *memmove(void *dest, const void *src, size_t n)
{
    char        *d;
    const char  *s;

    d = *(char *)dest;
    if (dest <= src)
    {
        while (n--)
            *d++ = *s++;
    }
    else
    {
        d += n;
        s += n;
        while(n--)
            *--d = *--s;
    }
    return (dest);
}