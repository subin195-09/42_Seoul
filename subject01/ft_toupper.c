#include "libft.h"

int     ft_toupper(int c)
{
    int change;

    change = 'a' - 'A';
    if(c >= 'a' && c <= 'z')
        return (c - change);
    return (c);
}