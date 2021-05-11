/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0_make_tok.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:39:18 by skim              #+#    #+#             */
/*   Updated: 2021/04/08 20:39:33 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int		is_char(char c, char *charset)
{
	int		size;
	int		i;

	size = ft_strlen(charset);
	i = -1;
	while (++i < size)
		if (c == charset[i])
			return (1);
	return (0);
}

int		count_word(char *s, char *charset)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (s[++i])
	{
		if (is_char(s[i], charset))
			i++;
		else
		{
			count++;
			while (s[i] && !is_char(s[i], charset))
				i++;
		}
	}
	return (count);
}

int		count_word_size(char *s, char *charset, int pos)
{
	int		i;
	int		count;

	i = pos;
	count = 0;
	while (s[i] && !is_char(s[i], charset))
	{
		count++;
		i++;
	}
	return (count);
}

char	**make_tok(char *str, char *charset)
{
	char	**rt;
	int		count;
	int		i;
	int		word_size;

	count = count_word(str, charset);
	if (!(rt = (char **)malloc(sizeof(char *) * (count + 1))))
		return (0);
	rt[count] = 0;
	count = 0;
	i = -1;
	while (str[++i])
	{
		if (is_char(str[i], charset))
			i++;
		else
		{
			word_size = count_word_size(str, charset, i);
			rt[count++] = ft_strndup(&str[i], word_size);
			i += word_size;
		}
	}
	return (rt);
}
