/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:22:10 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 19:02:06 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char *room1;
	const unsigned char *room2;

	room1 = (const unsigned char *)ptr1;
	room2 = (const unsigned char *)ptr2;
	while (n > 0)
	{
		if (*room1 != *room2)
			return (*room1 - *room2);
		room1++;
		room2++;
		n--;
	}
	return (0);
}
