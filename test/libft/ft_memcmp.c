/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:31:26 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 14:50:45 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *one;
	unsigned char *two;

	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while (one && two && n--)
	{
		if (*one != *two)
			break;
		one++;
		two++;
	}
	return (*one - *two);
}
