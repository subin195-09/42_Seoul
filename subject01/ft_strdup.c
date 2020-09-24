#include "libft.h"

char    *ft_strdup(const char *src)
{
    size_t  size;
    int     i;
    char    *dest;

    i = 0;
    size = ft_strlen(src);
    if (!(dest = malloc(size + 1)))
        return (0);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}