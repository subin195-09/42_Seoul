#include "libft.h"

void    *memset(void *p, int value, size_t size)
{
    char *result;
    int i;

    result = (char *)p;
    while (size--)
        *result++ = value;
    return (p);
}