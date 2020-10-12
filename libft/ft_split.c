/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:07:56 by skim              #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/10/11 12:36:57 by skim             ###   ########.fr       */
=======
/*   Updated: 2020/10/11 13:56:04 by skim             ###   ########.fr       */
>>>>>>> 49a43817219b918eb3cd3090f010d696cdbd66ca
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
