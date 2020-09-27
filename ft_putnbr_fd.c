#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    char *result;

    result = ft_itoa(n);
    write(fd, result, ft_strlen(result));
}