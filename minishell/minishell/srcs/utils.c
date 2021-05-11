/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:01:44 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:07:11 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	make_dup(int *fd, int type)
{
	dup2(*fd, type);
	close(*fd);
}

void	free_matrix(char ***matrix)
{
	int i;

	i = 0;
	while ((*matrix)[i])
	{
		free((*matrix)[i]);
		i++;
	}
	free((*matrix));
}

int		matrix_line_num(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

int		is_bslash(char *s, int i)
{
	int	count;

	count = 0;
	while (i > 0 && s[i - 1] == '\\')
	{
		count++;
		i--;
	}
	return (count % 2);
}

void	check_quote(char *s, int i, int *q_f, int *qq_f)
{
	if (s[i] == '\'')
		(*q_f) *= -1;
	else if (s[i] == '\"' && (i == 0 || !is_bslash(s, i)))
	{
		(*qq_f) *= -1;
	}
}
