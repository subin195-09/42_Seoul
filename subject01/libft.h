#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

void    *ft_memset(void *p, int value, size_t size);
void    ft_bzero(void *p, size_t size);
void    *ft_memcpy(void *dest, const void *src, size_t size);
void    *ft_memccpy(void *dest, const void *src, int c, size_t n);
void    *ft_memmove(void *dest, const void *src, size_t n);
void    *ft_memchr(const void *p, int value, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
size_t  ft_strlen(const char *str);
size_t  ft_strlcpy(char *dest, const char *src, size_t size);
size_t  ft_strlcat(char *dest, const char *src, size_t size);
char    *ft_strchr(const char *str, int c);
char    *ft_strrchr(const char *str, int c);
char    *strnstr(const char *big, const char *little, size_t len);
int     ft_strncmp(const char *s1, const char* s2, int n);
int     ft_atoi(const char *str);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);
void    *ft_calloc(size_t nelement, size_t bytes);
char    *ft_strdup(const char *src);

#endif