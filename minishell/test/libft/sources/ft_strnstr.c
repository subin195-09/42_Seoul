/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:53:30 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 15:58:44 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t len;

	if (*to_find == '\0')
		return (char *)str;
	len = ft_strlen(to_find);
	while (*str && n >= len)
	{
		if (*str == *to_find && ft_strncmp(str, to_find, len) == 0)
			return (char *)str;
		str++;
		n--;
	}
	return (0);
}
