/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_envp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:15 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 06:34:19 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(char *key, char ***en)
{
	int		i;
	char	*key_equal;

	i = -1;
	key_equal = ft_strjoin(key, "=");
	while ((*en)[++i])
	{
		if (!ft_strncmp(key_equal, (*en)[i], ft_strlen(key_equal)))
		{
			free(key_equal);
			return ((*en)[i]);
		}
	}
	free(key_equal);
	return (0);
}

char	*find_env_val(char *key, char ***en)
{
	int		i;
	char	*tmp;
	char	*rt;

	i = -1;
	tmp = find_env(key, en);
	if (!tmp)
		return (0);
	rt = ft_strdup(tmp + ft_strlen(key) + 1);
	return (rt);
}
