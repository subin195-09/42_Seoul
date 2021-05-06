/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:48 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 16:09:49 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_hist	*history_add(t_hist *nd)
{
	t_hist	*tmp;

	if (nd == 0)
	{
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		tmp->prev = 0;
		tmp->count = 0;
	}
	else
	{
		tmp = (t_hist*)malloc(sizeof(t_hist) * 1);
		tmp->content = 0;
		tmp->next = 0;
		nd->next = tmp;
		tmp->prev = nd;
		tmp->count = nd->count + 1;
	}
	return (tmp);
}
