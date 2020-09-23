#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t size)
{
    char *d;
    const char *s;

    // 나중에 확인해볼 것
    if (!dest && !src)
        return ;
    d = *(char *)dest;
    s = *(char *)src;
    while (size--)
        *d++ = *s++;
    return (dest);
}