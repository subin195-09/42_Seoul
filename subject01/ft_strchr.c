char    *ft_strchr(char *str, char c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (&str[i]);
        i++;
    }
    return (0);
}