/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3_1_ready_run.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 13:25:24 by skim              #+#    #+#             */
/*   Updated: 2021/04/16 13:38:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	list_push(t_list cmd, char ***comds)
{
	t_list	temp;
	int		i;

	i = -1;
	while ((*comds)[++i])
	{
		temp->arg = (char **)malloc(sizeof(char *) * 2);
		temp->arg[0] = ft_strdup((*cmods)[i]);
		free((*comds)[i]);
		temp->type = TYPE_PIPE;
		if (!((*comds)[i + 1]))
			temp->type = TYPE_END;
		// 기타 다른 인자들 초기화
		if (i == 0)
			cmd->child = temp;
		else
			cmd->sibling = temp;
		cmd = temp;
	}
}

void	find_direct(t_list cmd, char ***temp_arg)
{
	int		i;

	i = -1;
	while ((*temp_arg)[++i])
	{

	}
}

// 각 실행단위의 명령어를 |,>,>> 단위로 구분 후 type을 지정해준다.
void	get_type(t_list *cmd)
{// redirect인 경우 > 이후의 file open 후 얻은 descriptor를 fd[SIDE_IN]에 지정시켜준다.
	char	**pipe_cmds;
	char	**temp_arg;
	int		i;

	pipe_cmds = make_tok(cmd->arg[0], "|");
	i = -1;
	// 파이프 단위로 나뉜 것들을 일단 sibling 으로 연결
	list_push(cmd, &pipe_cmds);
	free(pipe_cmds);
	while (cmd)
	{
		// make_tok에 쌍 따움표, 따움표도 같이 처리 할 수 있도록 추가
		temp_arg = make_tok(cmd->arg[0], " ");
		// 다이렉트 부분을 치환시켜서 open 시켜준 후 fd[SIDE_IN]과 연결
		find_direct(cmd, &temp_arg);
		i = -1;
		while (temp_arg[++i])
			free(temp_arg[i]);
		free(temp_arg[i]);
		cmd = cmd->sibing;
	}
}
