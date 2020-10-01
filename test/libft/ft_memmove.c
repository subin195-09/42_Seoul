/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:52:19 by skim              #+#    #+#             */
/*   Updated: 2020/09/29 14:40:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
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
