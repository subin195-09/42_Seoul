#include "libft.h"

char    **ft_split(const char *s, char c)
{
    char **result;
    int start;
    int i;
    int j;
    int row;

    i = 0;
    row = 0;
    while (s[i])
    {
        if (s[i] == c)
            row++;
        i++;
    }
    if (!(result = (char **)malloc(sizeof(char *) * row + 2)))
        return (0);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (s[i] == c)
            i++;
        else
        {
            start = i;
            while (s[i] && s[i] != c)
                i++;
            if (!(result[j] = malloc(i - start + 2)))
                return (0);
            ft_strlcpy(result[j++], s + start, i - start + 1);
        }
    }
    result[j] = '\0';
    return (result);
}