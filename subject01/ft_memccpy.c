#include "libft.h"

void    *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
    char *s;

    if (!dest && !src)
        return ;
    s = *(unsigned char *)src;
    while(n--)
    {
        if(*s == c)
        {
            *(unsigned char *)dest++ = *s++;
            return dest;
        }
        *(unsigned char *)dest++ = *s++;
    }
    return ;
}