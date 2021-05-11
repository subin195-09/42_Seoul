/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ch_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:37:27 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 13:11:37 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_char(int size)
{
	char	alt[size * 2];
	int		i;

	i = -1;
	while (++i < size)
		alt[i] = '\b';
	while (i < size * 2)
		alt[i++] = ' ';
	write(1, alt, size * 2);
	write(1, alt, size);
}

void	get_ch_up_down_2(t_hist **nd, t_hist **anc)
{
	if ((*nd) != (*anc) && (*nd)->content)
		delete_char(ft_strlen((*nd)->content));
	if ((*nd) != (*anc))
	{
		if ((*nd)->next->content)
			write(1, (*nd)->next->content, ft_strlen((*nd)->next->content));
		(*nd) = (*nd)->next;
	}
}

void	get_ch_up_down(t_hist **nd, char c[2], t_hist **anc)
{
	if ((int)c[0] == 91)
	{
		read(0, c, 1);
		if ((int)c[0] == 65)
		{
			if ((*nd)->prev && (*nd)->content)
				delete_char(ft_strlen((*nd)->content));
			if ((*nd)->prev)
			{
				write(1, (*nd)->prev->content, ft_strlen((*nd)->prev->content));
				(*nd) = (*nd)->prev;
			}
		}
		else if ((int)c[0] == 66)
			get_ch_up_down_2(nd, anc);
	}
}

void	get_ch_erase(t_hist *nd)
{
	char	*back;

	if (nd->content && *(nd->content))
	{
		delete_char(ft_strlen(nd->content));
		back = ft_strndup(nd->content, ft_strlen(nd->content) - 1);
		free(nd->content);
		nd->content = back;
		write(1, nd->content, ft_strlen(nd->content));
	}
}

void	get_ch_ctld(t_hist **anc, t_hist **nd, char c[2])
{
	if (g_ex.is_signaled)
	{
		free((*anc)->content);
		(*anc)->content = 0;
		(*nd) = (*anc);
		g_ex.is_signaled = 0;
	}
	if ((int)c[0] == 4 && !(*nd)->content)
	{
		free_hist(*nd);
		write(2, "exit\n", 5);
		exit(0);
	}
	else if ((int)c[0] == 4 && (*nd)->content)
		;
}
