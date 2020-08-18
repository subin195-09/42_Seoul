char    *ft_strrchr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i--;
    while (i >= 0)
    {
        if (str[i] == c)
            return (&str[i]);
        i--;
    }
    return (0);
}