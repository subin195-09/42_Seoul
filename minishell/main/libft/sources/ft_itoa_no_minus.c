/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_no_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:34:40 by spark             #+#    #+#             */
/*   Updated: 2020/10/19 10:40:20 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilencal(int n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

char		*ft_itoa_no_minus(int n)
{
	int				len;
	char			*rt;
	unsigned int	tmp;

	len = ilencal(n / 10) + 1;
	if (n < 0)
		tmp = -n;
	else
		tmp = n;
	if (!(rt = malloc(len + 1)))
		return (0);
	rt[len] = 0;
	rt[--len] = '0' + (tmp % 10);
	while (tmp /= 10)
		rt[--len] = '0' + (tmp % 10);
	return (rt);
}
