/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:20:34 by skim              #+#    #+#             */
/*   Updated: 2020/10/17 13:45:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	t_info
{
	char		flag_in;
	int			width;
	int			precision;
	int			count_h;
	int			count_l;
	int			sign;
	int			left;
}				s_info;

int		ft_printf(const char *format, ...);
int		check_specifier(const char **format, va_list var);
int		format_write(const char **format, va_list var, s_info info);

#endif
