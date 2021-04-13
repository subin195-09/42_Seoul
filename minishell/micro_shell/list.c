/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:55:10 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 16:51:36 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "microshell.h"

// cmd 리스트에 av 인자 추가하기
int		add_arg(t_list *cmd, char *av)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = NULL;
	if (!(tmp = (char **)malloc(sizeof(*tmp) * (cmd->len + 2))))
		return (exit_fatal());
	i = 0;
	while (i < cmd->len)
	{
		tmp[i] = cmd->args[i];
		i++;
	}
	if (cmd->len > 0)
		free(cmd->args);
	cmd->args = tmp;
	cmd->args[i++] = strdup(av);
	cmd->args[i] = 0;
	cmd->len++;
	return (EXIT_SUCCESS);
}

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
