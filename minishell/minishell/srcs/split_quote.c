/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:08 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 01:21:24 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		count_size(char *str, char *set)
{
	int		count;
	int		i;
	int		qq_f;
	int		q_f;

	count = 1;
	i = 0;
	qq_f = 1;
	q_f = 1;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		check_quote(str, i, &q_f, &qq_f);
		if (ft_strchr(set, str[i]) && qq_f > 0 && q_f > 0)
		{
			if (!ft_strchr(set, str[i + 1]))
				count++;
		}
		i++;
	}
	return (count);
}

int		sep_2(char **str, char *set, char **rt)
{
	int	qq_f;
	int	q_f;
	int	i;

	i = 0;
	qq_f = 1;
	q_f = 1;
	while ((*str)[i])
	{
		check_quote((*str), i, &q_f, &qq_f);
		if (ft_strchr(set, (*str)[i]) && qq_f > 0 && q_f > 0)
		{
			(*rt) = ft_strndup(*str, i);
			break ;
		}
		i++;
	}
	return (i);
}

char	*sep(char **str, char *set)
{
	char	*rt;
	int		i;

	i = 0;
	while (ft_strchr(set, (*str)[i]))
		i++;
	(*str) += i;
	i = sep_2(str, set, &rt);
	if ((*str)[i] == 0)
	{
		rt = ft_strndup(*str, i);
		return (rt);
	}
	while (ft_strchr(set, (*str)[i]))
		i++;
	(*str) += i;
	return (rt);
}

char	**split_quote(char *str, char *set)
{
	char	**rt;
	int		size;
	int		i;

	if (!str || !*str)
		return (NULL);
	size = count_size(str, set);
	rt = (char **)malloc(sizeof(char *) * (size + 1));
	if (!rt)
		return (NULL);
	i = -1;
	while (++i < size)
		rt[i] = sep(&str, set);
	rt[i] = 0;
	return (rt);
}
