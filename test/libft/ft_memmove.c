/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:52:19 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 16:22:11 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (0);
	if (dest <= src)
	{
		while (n--)
			*(char *)dest++ = *(char *)src++;
	}
	else
	{
		dest += n;
		src += n;
		while (n--)
			*(char *)--dest = *(char *)--src;
	}
	return (dest);
}
