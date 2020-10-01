/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:27:03 by skim              #+#    #+#             */
/*   Updated: 2020/09/28 17:27:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *s;

	if (!dest && !src)
		return (0);
	s = (unsigned char *)src;
	while (n--)
	{
		if (*s == c)
			return (dest + 1);
		*(unsigned char *)dest++ = *s++;
	}
	return (0);
}
