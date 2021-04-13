/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:55:10 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 14:58:03 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

int		list_push(t_list **list, char *av)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return (exit)fatal());
	new->args = NULL;
	new->len = 0;
	new->type = TYPE_END;
	new->prew = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->prew 
	}
}
