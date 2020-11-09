/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:20:34 by skim              #+#    #+#             */
/*   Updated: 2020/11/09 18:04:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include "libft.h"

typedef struct	s_info
{
	char		padding;
	int			space;
	int			width;
	int			precision;
	int			count_h;
	int			count_l;
	int			check_sign;
	int			left;
	int			base;
}				t_info;

int				ft_printf(const char *format, ...);
int				check_specifier(const char **format, va_list var);
int				make_result(const char **format, t_info *info, va_list var);

int				make_result_int(t_info info, long long num);
int				make_result_uint(t_info info, unsigned long long num);
char			*int_width(t_info info, char *char_num, \
				int sign, long long num);
char			*int_pre(t_info info, char *char_num, int sign, long long num);
char			*ltoa_sign(long long num, int sign);
int				get_max(int a, int b, int c);
int				check_space(char **result, int len, int sign, t_info info);

int				make_result_char(t_info info, va_list var);
int				make_result_string(t_info info, va_list var);
char			*uni_encoder(wint_t num, int count_l, int *precision);

int				make_result_base(t_info *info, \
				unsigned long long num, char type);
char			*base_precision(char *temp_num, t_info info, char type);
char			*cut_and_paste_base(char *var_char, \
				t_info info, char type, int size);
char			*change_base(unsigned long long num, char *base);

int				make_result_p(t_info info, va_list var);

int				make_result_per(t_info info);

int				make_result_double(t_info info, va_list var);
int				make_result_e(t_info info, va_list var, char type);
int				float_factory(t_info info, char *char_num, int sign);
char			*check_sign(t_info info, double num, int sign, int exp);
int				what_is_sign(double num, t_info info);
char			*ft_dtoa_e(double num, int precision, int base, int exp);

int				zero_check_int(t_info info);
int				zero_check_char(t_info info);
int				zero_check_base(t_info info);

#endif
