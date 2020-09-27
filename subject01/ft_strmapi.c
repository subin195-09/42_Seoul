#include "libft.h"

char    *ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
    char            *result;
    unsigned int    i;

    if (!(result = malloc(ft_strlen(s) + 1)))
        return (0);
    i = 0;
    while (s[i])
        result[i++] = f(i, s[i]);
    result[i] = '\0';
    return (result);
}