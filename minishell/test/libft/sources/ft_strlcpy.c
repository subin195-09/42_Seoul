/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:12:37 by spark             #+#    #+#             */
/*   Updated: 2020/10/09 20:11:07 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while ((i + 1 < size) && (src[i]))
	{
		dest[i] = src[i];
		++i;
	}
	if (size != 0)
		dest[i] = 0;
	while (src[i])
		++i;
	return (i);
}
