/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:07:56 by skim              #+#    #+#             */
/*   Updated: 2020/10/09 12:47:41 by skim             ###   ########.fr       */
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

static int		make_split(char **result, const char *s, char c)
{
	int start;
	int	row;
	int	i;

	i = 0;
	row = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(result[row] = malloc(i - start + 1)))
				return (0);
			ft_strlcpy(result[row], &s[start], i - start + 1);
			row++;
		}
		else
			i++;
	}
	result[row] = 0;
	return (1);
}

char			**ft_split(const char *s, char c)
{
	char	**result;

	if (!s)
		return (0);
	if (!(result = (char **)malloc(check_word(s, c) + 1)))
		return (0);
	if (!make_split(result, s, c))
		return (0);
	return (result);
}
