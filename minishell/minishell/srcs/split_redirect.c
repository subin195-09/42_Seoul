/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:10:12 by spark             #+#    #+#             */
/*   Updated: 2021/05/07 01:51:54 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		redirect_count_2(char *arg, int *count, int *red_pos)
{
	int	qq_f;
	int	q_f;
	int	i;

	i = -1;
	qq_f = 1;
	q_f = 1;
	while (arg[++i])
	{
		check_quote(arg, i, &q_f, &qq_f);
		if (q_f > 0 && qq_f > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			if (arg[i + 1] == '>')
				i++;
			(*red_pos) = i;
			(*count)++;
		}
	}
	return (i);
}

int		redirect_count(char *arg)
{
	int	i;
	int	count;
	int	red_pos;

	count = 1;
	red_pos = -1;
	if (is_redirect(arg))
		return (1);
	i = redirect_count_2(arg, &count, &red_pos);
	if ((red_pos >= 0) && (red_pos != i - 1) && \
	(arg[0] != '>' && arg[0] != '<'))
		count++;
	return (count);
}

void	sep_redirect_2(char ***rt, int *size, char (*temp)[1024], int *j)
{
	if (ft_strlen(*temp) > 0)
	{
		(*rt)[*size] = ft_strdup(*temp);
		ft_memset(*temp, 0, 1024);
		(*j) = 0;
		(*size)++;
	}
}

void	sep_redirect(char ***rt, int *size, char *arg)
{
	char	temp[1024];
	int		q[2];
	int		j;
	int		i;

	i = -1;
	j = 0;
	q[1] = 1;
	q[0] = 1;
	ft_memset(temp, 0, 1024);
	while (arg[++i])
	{
		check_quote(arg, i, &q[0], &q[1]);
		if (q[0] > 0 && q[1] > 0 && (arg[i] == '>' || arg[i] == '<'))
		{
			sep_redirect_2(rt, size, &temp, &j);
			temp[j++] = arg[i];
			if (arg[i + 1] == '>')
				temp[j++] = arg[++i];
			sep_redirect_2(rt, size, &temp, &j);
		}
		else
			temp[j++] = arg[i];
	}
	sep_redirect_2(rt, size, &temp, &j);
}

char	**split_redirect(char **b_arg)
{
	char	**rt;
	int		size;
	int		i;

	size = 0;
	i = -1;
	while (b_arg[++i])
		size += redirect_count(b_arg[i]);
	rt = (char **)malloc(sizeof(char *) * (size + 1));
	rt[size] = 0;
	i = -1;
	size = 0;
	while (b_arg[++i])
	{
		if (redirect_count(b_arg[i]) == 1)
			rt[size++] = ft_strdup(b_arg[i]);
		else
			sep_redirect(&rt, &size, b_arg[i]);
	}
	return (rt);
}
