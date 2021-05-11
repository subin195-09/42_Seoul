/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_cutter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 21:12:43 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 18:09:30 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_sible_devide(t_nd *mother, t_nd **tmp_nd, int i, char **tmp)
{
	if (i == 0)
	{
		mother->child = new_nd(tmp[i]);
		*tmp_nd = mother->child;
	}
	else
	{
		(*tmp_nd)->sible = new_nd(tmp[i]);
		(*tmp_nd)->sible->prev = *tmp_nd;
		*tmp_nd = (*tmp_nd)->sible;
	}
}

t_nd	*big_cutter(char *str)
{
	char	**tmp;
	int		i;
	t_nd	*mother;
	t_nd	*tmp_nd;

	i = -1;
	tmp_nd = 0;
	tmp = split_quote(str, ";");
	if (!tmp)
		return (NULL);
	mother = new_nd(str);
	while (tmp[++i])
	{
		child_sible_devide(mother, &tmp_nd, i, tmp);
		free(tmp[i]);
	}
	free(tmp);
	tmp_nd = mother;
	return (mother);
}
