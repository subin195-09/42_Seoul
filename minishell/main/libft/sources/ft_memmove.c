/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:08:29 by spark             #+#    #+#             */
/*   Updated: 2020/10/28 02:22:53 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void *src, size_t n)
{
	void	*rt;

	if (!dest && !src)
		return (0);
	rt = dest;
	if (src < dest)
	{
		src += n;
		dest += n;
		while (n)
		{
			*(char *)--dest = *(char *)--src;
			n--;
		}
	}
	else
	{
		while (n)
		{
			*(char *)dest++ = *(char *)src++;
			n--;
		}
	}
	return (rt);
}
