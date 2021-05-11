/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 23:36:53 by spark             #+#    #+#             */
/*   Updated: 2020/10/05 21:56:48 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char *rt;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(rt = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memcpy(rt, s + start, len);
	rt[len] = '\0';
	return (rt);
}
