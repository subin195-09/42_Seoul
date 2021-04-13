/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:41:17 by skim              #+#    #+#             */
/*   Updated: 2021/04/13 19:37:48 by skim             ###   ########.fr       */
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

int		parse_arg(t_list **cmds, char *av)
{
	int		is_break;

	if (strcmp(";", av) == 0)
		is_break = 1;
	else
		is_break = 0;

	// ; 이고 list가 빈 상태일때
	if (is_break && !*cmds)
		return (EXIT_SUCCESS);
	// ; 가아니고, list가 빈 상태이거나, 바로전 리스트의 타입이 pipe or ; 일때
	else if (!is_break && (!*cmds || (*cmds)->type > TYPE_END))
		return (list_push(cmds, av));
	// pipe 일때
	else if (strcmp("|", av) == 0)
		(*cmds)->type = TYPE_PIPE;
	// ; 일때
	else if (is_break)
		(*cmds)->type = TYPE_BREAK;
	else
		return (add_arg(*cmds, av));
	return (EXIT_SUCCESS);
}

int		main(int ac, char **av, char **en)
{
	t_list	*cmds;
	int		i;
	int		ret;

	ret = EXIT_SUCCESS;
	cmds = NULL;
	i = 1;
	while (ac > i)
		parse_arg(&cmds, av[i++]);
	if (cmds)
		ret = exec_cmds(&cmds, en);
	list_clear(&cmds);
	return (ret);
}
