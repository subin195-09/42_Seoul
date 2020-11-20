/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 01:59:05 by skim              #+#    #+#             */
/*   Updated: 2020/11/20 20:01:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *str, int c)
{
	char *str_p;

	str_p = (char *)str;
	while (*str_p != c)
	{
		if (!*str_p)
			return (0);
		str_p++;
	}
	return (str_p);
}

char	*ft_strdup(const char *src)
{
	size_t	size;
	int		i;
	char	*dest;

	i = 0;
	size = ft_strlen(src);
	if (!(dest = malloc(size + 1)))
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strndup(const char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = malloc(n + 1)))
		return (0);
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		s1_len;
	int		s2_len;
	char	*result;
	int		i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len + s2_len == 0)
		return (ft_strdup(""));
	if (!(result = malloc(s1_len + s2_len + 1)))
		return (0);
	i = 0;
	while (i < s1_len)
		result[i++] = *s1++;
	while (i < s1_len + s2_len)
		result[i++] = *s2++;
	result[i] = 0;
	return (result);
}
