#include "libft.h"

char    *strnstr(const char *big, const char *little, size_t len)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if(!*little)
        return (big);
    while (big[i] && i < len)
    {
        while (little[j] && big[i] == little[j] && i + j < len)
        {
            i++;
            j++;
        }
        if (!little[j])
            return (&big[i - j]);
        i = i - j + 1;
        j = 0;
    }
    return (0);
}