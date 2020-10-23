/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:20:34 by skim              #+#    #+#             */
/*   Updated: 2020/10/23 21:45:27 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_result
{
	char		*sign;
	char		*temp_value;
	char		*result;
}				t_result;


typedef struct	s_info
{
	char		padding;
	int			width;
	int			precision;
	int			count_h;
	int			count_l;
	int			check_sign;
	int			left;
}				t_info;

int				ft_printf(const char *format, ...);
int				check_specifier(const char **format, va_list var);
int				make_result(const char **format, t_info *info, va_list var);

int				make_result_int(t_info info, va_list var);
void			cut_and_paste_int(char **result, char *char_num, t_info info);
char			*itoa_with_sign(int num, int sign);

int				make_result_char(t_info info, va_list var);
int				make_result_string(t_info info, va_list var);
char			*cut_and_paste_char(char *var_char, t_info info);

int				make_result_x(t_info info, va_list var, char type);
char			*change_hex(unsigned int num, int add);

int				make_result_uint(t_info info, va_list var);
int				count_num_unit(unsigned int num);

#endif
