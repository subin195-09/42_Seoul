#include "libft.h"

void    *ft_calloc(size_t nelement, size_t bytes)
{
    void    *p;

    if (!(p = malloc(nelement * bytes)))
        return (0);
    if (p == 0)
        return (p);
    ft_bzero(p, nelement * bytes);
    return (p);
}