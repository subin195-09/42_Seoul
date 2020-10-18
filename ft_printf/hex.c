/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:15:35 by skim              #+#    #+#             */
/*   Updated: 2020/10/18 20:04:22 by skim             ###   ########.fr       */
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
