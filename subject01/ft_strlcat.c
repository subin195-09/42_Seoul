unsigned int  ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    dest_len;
    unsigned int    src_len;
    int             i;

    dest_len = 0;
    src_len = 0;
    i = 0;
    while(dest[dest_len])
        dest_len++;
    while(src[src_len])
        src_len++;
    while(src[i] && i + dest_len + 1 < size)
    {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return (size < dest_len) ? (src_len + size) : (src_len + dest_len);
}