/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:14:30 by skim              #+#    #+#             */
/*   Updated: 2020/11/10 15:31:29 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef unsigned long long	t_ull;

typedef union				u_uni
{
	struct
	{
		unsigned long		man		:52;
		unsigned long		exp		:11;
		unsigned long		sign	:1;
	}						s_bit;
	double					num;
}							t_uni;

typedef struct				s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

void						*ft_memset(void *p, int value, size_t size);
void						ft_bzero(void *p, size_t size);
void						*ft_memcpy(void *dest, \
							const void *src, size_t size);
void						*ft_memccpy(void *dest, \
							const void *src, int c, size_t n);
void						*ft_memmove(void *dest, const void *src, size_t n);
void						*ft_memchr(const void *p, \
							int value, size_t n);
int							ft_memcmp(const void *s1, \
							const void *s2, size_t n);
size_t						ft_strlen(const char *str);
size_t						ft_strlcpy(char *dest, \
							const char *src, size_t size);
size_t						ft_strlcat(char *dest, \
							const char *src, size_t size);
char						*ft_strchr(const char *str, int c);
char						*ft_strrchr(const char *str, int c);
char						*ft_strnstr(const char *big, \
							const char *little, size_t len);
int							ft_strncmp(const char *s1, const char *s2, int n);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_calloc(size_t nelement, size_t bytes);
char						*ft_strdup(const char *src);

char						*ft_substr(const char *s, \
							unsigned int start, size_t len);
char						*ft_strjoin(const char *s1, const char *s2);
char						*ft_strtrim(const char *s1, const char *set);
char						**ft_split(const char *s, char c);
char						*ft_itoa(int n);
int							count_num(int n);

char						*ft_strmapi(const char *s, \
							char (*f)(unsigned int, char));
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);

char						*ft_ltoa(long long n);
int							count_num_long(long long n);
char						*ft_ultoa(unsigned long long n);
int							count_num_ulong(unsigned long long n);

char						*ft_dtoa(double num, int precision, int base);
t_ull						round_checker(double num, int precision);
char						*make_string(t_ull pre_num, \
							double num, int precision, long r_num);
t_ull						ft_pow(unsigned long long num, int exp);

void						ft_frees(int size, ...);

#endif
