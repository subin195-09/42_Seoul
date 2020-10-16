/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:15:35 by skim              #+#    #+#             */
/*   Updated: 2020/10/16 21:42:31 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	change_hex(const char **format, char *hex, int temp)
{
	char	hex_table[16];
	int		add;
	int		i;

	i = 0;
	if (**format == 'x')
		add = 'A' - 'a';
	else
		add = 0;
	while (i < 10)
	{
		hex_table[i] = (i + 1) + '0';
		i++;
	}
	while (i < 16)
	{
		hex_table[i] = 'a' + add + (i - 10);
		i++;
	}
}

void	write_int(const char **format, va_list var, s_info info)
{
	int		temp;
	int		count;
	char	*hex;
	char	*temp_result;

	temp = va_arg(var, int);
	change_hex(format, hex, temp);
	if (**format == 'd' || **format == 'i')
		count = count_num(temp);
	else
		count = ft_strlen(hex);
	if (info.width > count && info.flag_in)
	{
		while (info.width > count)
		{
			write(1, info.flag_in, 1);
			info.width--;
		}
	}
	if (**format == 'd' || **format == 'i')
		ft_putnbr_fd(temp, 1);
	else
		ft_putstr_fd(hex, 1);
	(*format)++;
}

int		format_write(const char **format, va_list var, s_info info)
{
	if (**format == 'd' || **format == 'i' ||
			**format == 'x' || **format == 'X')
	{
		ft_putnbr_fd(va_arg(var, int), 1);
		(*format)++;
	}
	return (0);
}
