#include "libft.h"

size_t      ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t  dest_len;
    size_t  src_len;
    int     i;

    dest_len = 0;
    src_len = 0;
    i = 0;
    while(dest[dest_len])
        dest_len++;
    while(src[src_len])
        src_len++;
    while(src[i] && i + dest_len + 1 < size)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (size < dest_len) ? (src_len + size) : (src_len + dest_len);
}