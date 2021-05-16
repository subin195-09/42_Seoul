/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 14:38:34 by skim              #+#    #+#             */
/*   Updated: 2020/09/28 18:40:12 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *p, int value, size_t size)
{
	unsigned char *result;

	result = (unsigned char *)p;
	while (size--)
		*result++ = value;
	return (p);
}
