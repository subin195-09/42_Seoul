/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:08:29 by spark             #+#    #+#             */
/*   Updated: 2020/10/28 02:23:18 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove_f(void *dest, void *src, size_t n)
{
	void	*rt;

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
