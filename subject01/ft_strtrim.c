#include "libft.h"

char    *ft_strtrim(const char *s1, const char *set)
{
    char *result;
    int start;
    int end;

    if(!set && !s1)
        return (ft_strdup(""));
    start = 0;
    while(ft_strchr(set, s1[start]))
        start++;
    end = ft_strlen(s1) - 1;
    while(ft_strchr(set, s1[end]))
        end--;
    if(!(result = malloc(end - start + 2)))
        return (0);
    ft_strlcpy(result, s1 + start, end - start + 1);
    return (result);
}