/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:59:29 by skim              #+#    #+#             */
/*   Updated: 2020/09/28 16:59:31 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int value, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)p;
	while (n--)
	{
		if (*temp == (unsigned char)value)
			return (p);
		temp++;
	}
	return (0);
}
