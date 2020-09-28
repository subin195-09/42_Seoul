/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:08:17 by skim              #+#    #+#             */
/*   Updated: 2020/09/28 16:22:21 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (0);
	d = (char *)dest;
	s = (char *)src;
	while (size--)
		*d++ = *s++;
	return (dest);
}
