/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:09:38 by spark             #+#    #+#             */
/*   Updated: 2021/05/06 19:15:05 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	terminal_set(struct termios	*term, struct termios *back)
{
	tcgetattr(STDIN_FILENO, term);
	tcgetattr(STDIN_FILENO, back);
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, term);
}

void	get_ch_difin(t_hist **nd, t_hist **anc, char c, \
					char (*fake_db)[(*nd)->count + 1][PATH_MAX])
{
	if (c == '\n')
	{
		free((*anc)->content);
		(*anc)->content = ft_strdup((*nd)->content);
		if ((*fake_db)[(*nd)->count][0])
		{
			free((*nd)->content);
			(*nd)->content = ft_strdup((*fake_db)[(*nd)->count]);
		}
		(*nd) = (*anc);
	}
	else
	{
		if ((*fake_db)[(*nd)->count][0] == 0)
			ft_strlcpy((*fake_db)[(*nd)->count],\
			(*nd)->content, ft_strlen((*nd)->content) + 1);
	}
}

int		get_ch_general(t_hist **nd, t_hist **anc, char c[2], \
						char (*fake_db)[(*nd)->count + 1][PATH_MAX])
{
	char	*tmp;

	write(1, c, 1);
	if ((*anc) != (*nd))
		get_ch_difin(nd, anc, c[0], fake_db);
	if (c[0] == '\n')
		return (-1);
	if (!(*nd)->content)
		(*nd)->content = ft_strdup(c);
	else
	{
		c[1] = 0;
		tmp = (*nd)->content;
		(*nd)->content = ft_strjoin(tmp, c);
		free(tmp);
	}
	return (1);
}

int		get_ch_default(t_hist **nd, t_hist **anc, char c[2], \
						char (*fake_db)[(*nd)->count + 1][PATH_MAX])
{
	if ((int)c[0] == 127)
		get_ch_erase(*nd);
	else
	{
		if (get_ch_general(nd, anc, c, fake_db) < 0)
			return (-1);
	}
	return (1);
}

char	*get_ch(t_hist *nd)
{
	char			c[2];
	struct termios	term;
	struct termios	back;
	char			fake_db[nd->count + 1][PATH_MAX];
	t_hist			*anc;

	c[1] = 0;
	terminal_set(&term, &back);
	anc = nd;
	ft_memset(fake_db, 0, sizeof(fake_db));
	while (read(0, c, 1) > 0)
	{
		get_ch_ctld(&anc, &nd, c);
		if ((int)c[0] == 27)
		{
			read(0, c, 1);
			get_ch_up_down(&nd, c, &anc);
		}
		else if (get_ch_default(&nd, &anc, c, &fake_db) < 0)
			break ;
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &back);
	return (nd->content);
}
