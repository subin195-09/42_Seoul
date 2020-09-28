#include "libft.h"

int     ft_strncmp(const char *s1, const char *s2, int n)
{
    int i;

    i = 0;
    while(i < n && s1[i] && s2[i])
    {
        if(s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
