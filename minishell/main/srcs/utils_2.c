/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:02:51 by spark             #+#    #+#             */
/*   Updated: 2021/05/05 23:18:26 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_nd	*new_nd(char *name)
{
	t_nd	*tmp_nd;

	tmp_nd = malloc(sizeof(t_nd) * 1);
	if (!tmp_nd)
		return (NULL);
	if (name != NULL)
	{
		tmp_nd->args = (char **)malloc(sizeof(char *) * 2);
		if (!tmp_nd->args)
			return (NULL);
		tmp_nd->args[0] = ft_strdup(name);
		tmp_nd->args[1] = 0;
	}
	tmp_nd->child = 0;
	tmp_nd->sible = 0;
	tmp_nd->prev = 0;
	tmp_nd->type = -1;
	tmp_nd->re.rdrt_type = 0;
	tmp_nd->re.rdrt_fd = 0;
	tmp_nd->re.rdrt_name = 0;
	tmp_nd->re.rdrt_in_type = 0;
	tmp_nd->re.rdrt_in_fd = 0;
	tmp_nd->re.rdrt_in_name = 0;
	return (tmp_nd);
}

t_nd	*child_rewind(t_nd *coms)
{
	t_nd	*tmp;

	tmp = coms;
	while (tmp->child)
		tmp = tmp->child;
	return (tmp);
}

void	print_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		printf("{%s},", args[i]);
}

void	print_list(t_nd *com)
{
	t_nd	*tmp_nd;
	t_nd	*tmp_nd2;

	tmp_nd = com;
	tmp_nd2 = com;
	print_args(tmp_nd->args);
	printf("\n");
	if (tmp_nd2->child)
	{
		tmp_nd2 = tmp_nd2->child;
		tmp_nd = tmp_nd2;
		printf("->");
		print_list(tmp_nd2);
	}
	while (tmp_nd->sible)
	{
		tmp_nd = tmp_nd->sible;
		print_list(tmp_nd);
	}
}

void	print_list_2(t_hist *com)
{
	t_hist	*tmp;

	tmp = com;
	while (tmp)
	{
		printf("[%s]<-", tmp->content);
		if (tmp->prev)
			tmp = tmp->prev;
		else
			break ;
	}
}
