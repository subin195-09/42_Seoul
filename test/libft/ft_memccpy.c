/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:27:03 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 16:06:46 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	if (!dest && !src)
		return (0);
	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return (&d[i] + 1);
		d[i] = s[i];
		i++;
	}
	return (0);
}
