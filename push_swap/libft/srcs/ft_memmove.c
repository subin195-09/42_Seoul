/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:52:19 by skim              #+#    #+#             */
/*   Updated: 2020/10/05 21:53:57 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;

	if (!dest && !src)
		return (0);
	dp = (unsigned char *)dest;
	sp = (unsigned char *)src;
	if (dp <= sp)
	{
		while (n--)
			*dp++ = *sp++;
	}
	else
	{
		dp += n;
		sp += n;
		while (n--)
			*--dp = *--sp;
	}
	return (dest);
}
