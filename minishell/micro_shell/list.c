/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:55:10 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 16:57:17 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// 새로운 list 를 끝에 추가하고  그 끝을 가리키게 한다.
int		list_push(t_list **list, char *av)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(*new))))
		return exit_fatal();
	new->args = NULL;
	new->len = 0;
	new->type = TYPE_END;
	new->prev = NULL;
	new->next = NULL;
	if (*list)
	{
		(*list)->next = new;
		new->prev = *list;
	}
	*list = new;
	return (add_arg(new, av));
}

// list 헤드로 이동
int		list_rewind(t_list **list)
{
	while (*list && (*list)->prev)
		*list = (*list)->prev;
	return (EXIT_SUCCESS);
}

int		list_clear(t_list **cmds)
{
	t_list	*tmp;
	int		i;

	list_rewind(cmds);
	while (*cmds)
	{
		tmp = (*cmds)->next;
		i = 0;
		while (i < (*cmds)->len)
			free((*cmds)->args[i++]);
		free((*cmds)->args);
		free(*cmds);
		*cmds = tmp;
	}
	*cmds = NULL;
	return (EXIT_SUCCESS);
}
