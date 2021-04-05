/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:59:29 by skim              #+#    #+#             */
/*   Updated: 2020/09/30 19:39:44 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int value, size_t n)
{
	unsigned char *up;

	up = (unsigned char *)p;
	while (n--)
	{
		if (*up == (unsigned char)value)
			return (up);
		up++;
	}
	return (0);
}
