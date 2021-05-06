/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:38:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 20:40:19 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *p, int tg, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)p == (unsigned char)tg)
			return ((void*)p);
		p++;
	}
	return (NULL);
}
