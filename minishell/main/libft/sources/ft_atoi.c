/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:27:00 by spark             #+#    #+#             */
/*   Updated: 2020/10/11 15:45:22 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int rt;
	int indic;
	int repeat;

	rt = 0;
	repeat = 0;
	indic = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			indic *= -1;
	while ('0' <= *str && *str <= '9')
	{
		rt *= 10;
		rt += (indic * (*(str++) - '0'));
		repeat++;
		if (repeat > 10 && indic == -1)
			return (0);
		else if (repeat > 10 && indic != -1)
			return (-1);
	}
	return (rt);
}
