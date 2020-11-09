/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:29:51 by skim              #+#    #+#             */
/*   Updated: 2020/10/12 14:30:18 by skim             ###   ########.fr       */
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
		else
			i++;
	}
	return (word);
}

static int		count_size(const char *s, char c)
{
	int size;

	size = 0;
	while (*s && *s != c)
	{
		size++;
		s++;
	}
	return (size);
}

static char		**all_free(char **result, int row)
{
	int i;

	i = 0;
	while (i < row)
		free(result[i++]);
	free(result);
	return (0);
}

char			**ft_split(const char *s, char c)
{
	char	**result;
	int		size;
	int		row;

	row = 0;
	if (!s)
		return (0);
	if (!(result = (char **)malloc(sizeof(char *) * (check_word(s, c) + 1))))
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			size = count_size(s, c);
			if (!(result[row] = malloc(size + 1)))
				return (all_free(result, row));
			ft_strlcpy(result[row++], s, size + 1);
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[row] = 0;
	return (result);
}
