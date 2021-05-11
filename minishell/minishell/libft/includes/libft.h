/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:32:23 by hyunja            #+#    #+#             */
/*   Updated: 2021/05/06 00:02:46 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef unsigned long long				t_ull;
typedef unsigned int					t_ui;
typedef union							u_uni_bigint
{
	double								d;
}										t_uni_bigint;
typedef union							u_double
{
	double								d;
	struct
	{
		unsigned long					sgnfi	:52;
		unsigned long					expond	:11;
		unsigned long					sign	:1;
	}									s_bit;
}										t_double;

typedef struct							s_list
{
	void								*content;
	struct s_list						*next;
}										t_list;

typedef struct							s_str_set
{
	const char							*str_to_pharse;
	char								*str_flaged;
	char								*str_body;
	char								*str_to_print;
}										t_str_set;

typedef struct							s_flag_set
{
	int									lefted;
	int									zeroflag;
	int									spaceflag;
	int									plus_flag;
	int									shap_flag;
	int									just_bd;
	int									e_absilon;
	int									add;
	int									ull_on;
}										t_flag_set;

typedef struct							s_lenth_set
{
	int									width;
	int									precision;
	int									origin_precs;
	int									total_len;
	int									print_len;
}										t_lenth_set;

typedef struct							s_ex_type
{
	int									l;
	int									ll;
	int									h;
	int									hh;
}										t_ex_type;

typedef struct							s_libset
{
	void								*val;
	char								type;
	long long							num;
	unsigned char						chr;
	char								*va_str;
	int									precision_yn;
	int									rt_byte;
	int									pre_is_zero;
	int									db_aster_pre;
	int									e_expond;
	t_double							f;
	va_list								*list;
	t_str_set							strs;
	t_flag_set							flags;
	t_lenth_set							lenths;
	t_ex_type							ex;
}										t_libset;

char									*ft_strnstr(const char *str, \
										const char *to_find, size_t n);
int										ft_isdigit(int n);
int										ft_putstr_fd(char *s, int fd);
size_t									ft_strlcpy(char *dest, \
										const char *src, unsigned int size);
size_t									ft_strlen(const char *str);
int										ft_memcmp(const void *ptr1,\
										const void *ptr2, size_t n);
void									inttochar_fd(int n, int fd);
char									*ft_strchr(const char *str, int tg);
void									ft_bzero(void *p, size_t n);
char									*ft_strjoin(char const *s1,\
										char const *s2);
int										ft_isascii(int n);
void									*ft_memcpy(void *dest, const void *src,\
										size_t n);
char									*ft_strnstr(const char *str, \
										const char *to_find, size_t n);
void									*ft_memccpy(void *dest, void *src, \
										int c, size_t n);
int										ft_isprint(int n);
void									ft_putendl_fd(char *s, int fd);
int										ft_toupper(int n);
char									*ft_strrchr(char *str, int tg);
int										ft_isalpha(int c);
void									*ft_memchr(const void *p, int tg, \
										size_t n);
void									ft_putchar_fd(char c, int fd);
void									*ft_memset(void *p, int tg, size_t n);
char									*ft_substr(char const *s, \
										unsigned int start, size_t len);
int										ft_strncmp(const char *s1, \
										const char *s2, size_t n);
char									*ft_strmapi(char const *s, \
										char (*f)(unsigned int, char));
void									*ft_memmove(void *dest, \
										void *src, size_t n);
size_t									ft_strlcat(char *dest, \
										const char *src, size_t size);
void									*ft_calloc(size_t many, size_t size);
char									*ft_strdup(const char *str);
int										ft_atoi(const char *str);
int										ft_isalnum(int n);
char									*ft_itoa(int n);
int										ft_tolower(int n);
char									**ft_split(char const *str, char c);
void									ft_putnbr_fd(int n, int fd);
char									*ft_strtrim(char const *s1, \
										char const *set);

char									*ft_strndup(const char *str, size_t n);
char									*ft_strchrs(const char *str, \
										char *to_find);
void									*ft_memset_chr(char *p, char c, int n);
long long								ft_int_len(long long n);
char									*ft_itoa_no_minus(int n);
char									*ft_ltoa(long long n);
int										is_space(char c);
char									*ft_convert_base_u(char *nbr, \
										char *base_from, char *base_to);
char									*ft_print_memory(void *addr, \
										unsigned int size);
char									*ft_strcat_chr(char *s1, char c);
char									*ft_ltoa_no_minus(long long n);
char									*ft_chrcat_chr(unsigned char c1, \
										unsigned char c2);
void									*ft_memmove_f(void *dest, \
										void *src, size_t n);
char									*ft_ultoa(unsigned long long n);
char									*ft_convert_base(char *nbr, \
										char *base_from, char *base_to);
char									*ft_ltoa_no_minus_round(long long n);
void									ft_free_va(int cnt, ...);
char									*ft_strjoin_free(char *s1, char *s2);
int										ft_db_len(t_libset *set, double n, \
										int pre, int wid);
char									*ft_dtoa_in_fix(t_libset *set,\
										double n, int pre, int wid);
unsigned long long						ft_power(int time);
t_list									*ft_lstnew(void *content);
void									ft_lstadd_front(t_list **lst, \
										t_list *new);
void									ft_lstadd_back(t_list **lst, \
										t_list *new);
int										ft_lstsize(t_list *lst);
t_list									*ft_lstlast(t_list *lst);
void									ft_lstdelone(t_list *lst, \
										void (*del)(void *));
void									ft_lstclear(t_list **lst, \
										void (*del)(void *));
void									ft_lstiter(t_list *lst, \
										void (*f)(void *));
t_list									*ft_lstmap(t_list *lst, \
										void *(*f)(void *), \
										void (*del)(void *));
char									*ft_zero_maker(t_libset *set, \
										int pre, int wid);
char									*ft_manti_to_a(t_libset *set, \
										double manti, char *base, int pre);
char									ft_array_round(t_libset *set, \
										char *str, int pre);
int										ft_ilencal(long long n);
int										get_next_line(int fd, char **line);
int										ft_strcmp(const char *s1,\
										const char *s2);
char									*ft_strcat(char *dest, const char *src);

#endif
