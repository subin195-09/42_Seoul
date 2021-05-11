/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:16:24 by spark             #+#    #+#             */
/*   Updated: 2020/11/20 18:47:20 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t index;
	size_t d_i;
	size_t s_i;

	index = 0;
	d_i = 0;
	s_i = 0;
	while (index < size && dest[d_i])
	{
		d_i++;
		index++;
	}
	while (index + 1 <= size && src[s_i])
	{
		dest[d_i++] = src[s_i++];
		index++;
	}
	if (index < size)
		dest[d_i] = 0;
	while (src[s_i])
	{
		index++;
		s_i++;
	}
	return (index);
}
