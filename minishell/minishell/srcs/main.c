/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:53 by spark             #+#    #+#             */
/*   Updated: 2021/05/08 18:07:32 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(char ***en)
{
	int	i;

	i = -1;
	while ((*en)[++i])
		free((*en)[i]);
	free(*en);
}

void	init_env(char ***env, char *en[])
{
	int		i;
	int		j;

	i = 0;
	while (en[i])
		i++;
	if (!(*env = (char **)malloc(sizeof(char *) * (i + 1))))
		return ;
	(*env)[i] = 0;
	j = -1;
	while (++j < i)
		(*env)[j] = ft_strdup(en[j]);
}

int		main(int ac, char *av[], char *en[])
{
	char	**env;
	char	rt;

	g_ex.exit_code = 0;
	init_env(&env, en);
	rt = start_shell(&env, av[0]);
	free_env(&env);
	exit(g_ex.exit_code);
	(void)ac;
}
