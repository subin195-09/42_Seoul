/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:07:56 by skim              #+#    #+#             */
/*   Updated: 2020/10/06 18:54:55 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_word(const char *s, char c)
{
	int i;
	int word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
		i++;
	}
	return (word);
}

char			**ft_split(const char *s, char c)
{
	char	**result;
	int		row;
	char	*start;

	if (!s)
		return (0);
	if (!(result = (char **)malloc(check_word(s, c) + 1)))
		return (0);
	row = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			if (!(result[row] = malloc(s - start + 1)))
				return (0);
			ft_strlcpy(result[row++], start, s - start + 1);
		}
		s++;
	}
	result[row] = 0;
	return (result);
}
