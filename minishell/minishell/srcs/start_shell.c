/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_shell.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 22:34:06 by spark             #+#    #+#             */
/*   Updated: 2021/05/10 11:43:42 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_strchr(SEP, line[i]))
		i++;
	if (!line[i])
		return (0);
	return (1);
}

void	history_connecter(t_hist **history)
{
	if ((*history)->prev)
	{
		*history = (*history)->prev;
		free((*history)->next);
		(*history)->next = 0;
	}
	else
	{
		free(*history);
		*history = 0;
	}
}

void	basic_ready(t_hist **history, char **line)
{
	if (g_ex.pid == 0)
		write(1, "gun_mandoo_shell > ", ft_strlen("gun_mandoo_shell > "));
	*history = history_add(*history);
	*line = get_ch(*history);
	if (!(*line))
		history_connecter(history);
}

int		start_shell(char ***en, char *av)
{
	int		status;
	char	*line;
	t_nd	*coms;
	t_hist	*history;

	status = EXIT_SUCCESS;
	start_write();
	history = 0;
	signal(SIGINT, (void *)signal_ctlc);
	signal(SIGQUIT, (void *)signal_ctlslash);
	while (status == EXIT_SUCCESS)
	{
		basic_ready(&history, &line);
		if (line && *line && line_check(line) && \
		synerror_checker(line, ';') >= 0)
		{
			coms = big_cutter(line);
			status = run_cmd(coms->child, en, av);
			free_nd(coms);
		}
		g_ex.pid = 0;
	}
	free_hist(history);
	return (0);
}
