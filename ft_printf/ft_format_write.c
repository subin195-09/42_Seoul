/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:15:35 by skim              #+#    #+#             */
/*   Updated: 2020/10/16 18:36:50 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		format_write(const char **format, va_list var, s_info info)
{
	if (**format == 'd' || **format == 'i')
	{
		ft_putnbr_fd(va_arg(var, int), 1);
		(*format)++;
	}
	return (0);
}
