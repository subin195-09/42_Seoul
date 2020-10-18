/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:20:34 by skim              #+#    #+#             */
/*   Updated: 2020/10/18 21:50:53 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_info
{
	char		padding;
	int			width;
	int			precision;
	int			count_h;
	int			count_l;
	int			sign;
	int			left;
}				t_info;

int		ft_printf(const char *format, ...);
int		check_specifier(const char **format, va_list var);
int		make_result(const char **format, t_info info, va_list var);
int		make_result_int(t_info info, va_list var);

#endif
