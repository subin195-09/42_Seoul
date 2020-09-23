#include "libft.h"

char    *ft_strdup(const char *src)
{
    size_t  size;
    int     i;
    char    *dest;

    i = 0;
    size = 0;
    while (src[size])
        size++;
    if (!(dest = (char *)malloc(sizeof(char) * size)))
        return (0);
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}