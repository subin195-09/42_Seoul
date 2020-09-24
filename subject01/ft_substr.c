#include "libft.h"

char    *ft_substr(const char *s, unsigned int start, size_t len)
{
    int s_len;
    int i;
    char *substr;

    i = 0;
    s_len = ft_strlen(s);
    if (start + len > s_len || !s || !len)
        return (ft_strdup(""));
    if(!(substr = malloc(len + 1)))
        return (0);
    ft_strlcpy(substr, s + start, len + 1);
    return (substr); 
}