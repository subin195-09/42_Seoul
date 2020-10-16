/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 18:37:42 by skim              #+#    #+#             */
/*   Updated: 2020/10/16 15:32:09 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_flag(const char **format, va_list var)
{
	int		count_bytes;

	count_bytes = 0;
	if (**format == 'L')
	{
		return (0);
	}
	else if (**format == ' ')
	{
		return (0);
	}
	else if (**format >= '0' && **format <= '9')
	{
		return (0);
	}
	else if (**format == '+')
	{
		return (0);
	}
	else if (**format == '.')
	{
		return (0);
	}
	else if (**format == '#')
	{
		return (0);
	}
	else
	{
		if (**format == 'd')
		{
			ft_putnbr_fd(va_arg(var, int), 1);
		}
	}
	return (count_bytes);
}
