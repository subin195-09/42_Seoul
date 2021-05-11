/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:08:49 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 07:38:10 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_env(char ***en, char *str)
{
	char	**new_en;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 2));
	if (!new_en)
		return (0);
	while ((*en)[++i])
	{
		new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free(*en);
	new_en[++j] = ft_strdup(str);
	new_en[++j] = 0;
	return (new_en);
}

char	**update_env(char ***en, char *str, char *find_en)
{
	char	**new_en;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_en = malloc(sizeof(char*) * ((matrix_line_num(*en)) + 1));
	if (!new_en)
		return (0);
	while ((*en)[++i])
	{
		if (find_en == (*en)[i])
			new_en[++j] = ft_strdup(str);
		else
			new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free(*en);
	new_en[++j] = 0;
	return (new_en);
}

char	**delete_env(char ***en, char *find_en)
{
	char	**new_en;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new_en = malloc(sizeof(char *) * (matrix_line_num(*en)));
	if (!new_en)
		return (0);
	while ((*en)[++i])
	{
		if ((*en)[i] != find_en)
			new_en[++j] = ft_strdup((*en)[i]);
		free((*en)[i]);
	}
	free((*en));
	new_en[++j] = 0;
	return (new_en);
}
