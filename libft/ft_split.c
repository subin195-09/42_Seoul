/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:07:56 by skim              #+#    #+#             */
/*   Updated: 2020/10/03 17:21:56 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_word(const char *s, char c)
{
	int i;
	int row;

	i = 0;
	row = 0;
	while (s[i])
	{
		if (s[i] == c)
			row++;
		i++;
	}
	return (row);
}

static int		make_split(char **result, const char *s, char c)
{
	int	i;
	int	row;
	int	start;

	i = 0;
	row = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			if (!(result[row] = malloc(i - start + 2)))
				return (0);;
			ft_strlcpy(result[row++], s + start, i - start + 1);
		}
		i++;
	}
	result[row] = 0;
	return (1);
}

char			**ft_split(const char *s, char c)
{
	char	**result;
	int		row;

	if (!s)
		return (0);
	row = check_word(s, c);
	if (!(result = (char **)malloc(sizeof(char *) * row + 2)))
		return (0);
	if (!(make_split(result, s, c)))
		return (0);
	return (result);
}
