#include "libft.h"

int     ft_tolower(int c)
{
    int change;

    change = 'a' - 'A';
    if (c >= 'A' && c <= 'Z')
        return (c + change);
    return (c);
}