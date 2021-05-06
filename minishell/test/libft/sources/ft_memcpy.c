/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:26:43 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 20:36:02 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*rt;
	size_t			i;

	if (!dest && !src)
		return (0);
	rt = dest;
	i = 0;
	while (i < n)
	{
		*(char*)dest++ = *(char*)src++;
		i++;
	}
	return (rt);
}
