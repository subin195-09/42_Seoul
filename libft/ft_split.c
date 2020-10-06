/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:07:56 by skim              #+#    #+#             */
/*   Updated: 2020/10/06 23:24:21 by skim             ###   ########.fr       */
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
	int 	i;
	int		start;

	if (!s)
		return (0);
	if (!(result = (char **)malloc(check_word(s, c) + 1)))
		return (0);
	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(result[row] = malloc(i - start + 1)))
				return (0);
			ft_strlcpy(result[row++], &s[start], s - start + 1);
		}
	}
	result[row] = 0;
	return (result);
}
