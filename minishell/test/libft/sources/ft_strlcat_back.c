/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunja <hyunja@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:16:24 by spark             #+#    #+#             */
/*   Updated: 2020/10/06 10:14:18 by hyunja           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t index;

	index = 0;
	while (index < size && *dest)
	{
		dest++;
		index++;
	}
	while (index + 1 < size && *src)
	{
		*dest++ = *src++;
		index++;
	}
	if (index < size)
		*dest = 0;
	while (*src)
	{
		index++;
		src++;
	}
	return (index);
}
