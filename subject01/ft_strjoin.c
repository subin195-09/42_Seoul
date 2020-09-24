#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    int     s1_len;
    int     s2_len;
    int     i;
    char    *result;

    i = 0;
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    if (!(result = malloc(s1_len + s2_len + 1)))
        return (0);
    if (s1_len + s2_len == 0)
        return (strdup(""));
    ft_strlcpy(result, s1, s1_len + 1);
    ft_strlcat(result, s2, s1_len + s2_len + 1);
    return (result);   
}