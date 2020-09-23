#include "libft.h"

void    ft_bzero(void *p, size_t size)
{
    while (size--)
        *(char *)p++ = 0;
}