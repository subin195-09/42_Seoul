/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 23:24:19 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 23:47:50 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	char	*rt;
	size_t	i;

	len = ft_strlen(str);
	if (!(rt = malloc(sizeof(char) * len + 1)))
		return (0);
	i = 0;
	while (i < n)
	{
		rt[i] = str[i];
		i++;
	}
	rt[i] = 0;
	return (rt);
}

static size_t	word_len(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

static size_t	is_cutter(char const *s, char c)
{
	size_t count;

	count = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		count++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (count);
}

static void		ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	size_t	count;
	size_t	w_len;
	size_t	i;

	count = is_cutter(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		w_len = word_len(s, c);
		if (!(result[i] = ft_strndup(s, w_len)))
		{
			ft_free_arr(result, i - 1);
			return (0);
		}
		s += w_len;
		i++;
	}
	result[count] = 0;
	return (result);
}
