/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 10:22:41 by hyunja            #+#    #+#             */
/*   Updated: 2020/10/28 04:24:45 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ilencal(unsigned long long n)
{
	return (n == 0 ? 0 : 1 + ilencal(n / 10));
}

char				*ft_ultoa(unsigned long long n)
{
	int				len;
	char			*rt;

	len = ilencal(n / 10) + 1;
	if (!(rt = malloc(len + 1)))
		return (0);
	rt[len] = 0;
	rt[--len] = '0' + (n % 10);
	while (n /= 10)
		rt[--len] = '0' + (n % 10);
	return (rt);
}
