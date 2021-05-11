/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark <spark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:49:59 by spark             #+#    #+#             */
/*   Updated: 2021/02/25 23:16:07 by spark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		rt_room(char **room, char **line)
{
	char	*anchor;
	char	*tmp;

	if (ft_strchr(*room, '\n'))
	{
		tmp = 0;
		anchor = ft_strchr(*room, '\n');
		*anchor = 0;
		*line = ft_strdup(*room);
		tmp = ft_strdup(anchor + 1);
		free(*room);
		*room = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	else
	{
		*line = ft_strdup(*room);
		free(*room);
		*room = 0;
		return (0);
	}
}

static void		rt_n_store(char **room, char **line)
{
	char	*anchor;
	char	*tmp;

	tmp = 0;
	anchor = ft_strchr(*room, '\n');
	*anchor = 0;
	*line = ft_strdup(*room);
	tmp = ft_strdup(anchor + 1);
	free(*room);
	*room = ft_strdup(tmp);
	free(tmp);
}

int				get_next_line(int fd, char **line)
{
	static char *room[OPEN_MAX + 1];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			rt;

	rt = 0;
	if (!line || fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((rt = read(fd, buff, BUFFER_SIZE)) >= 0)
	{
		buff[rt] = 0;
		tmp = !(room[fd]) ? ft_strdup(buff) : ft_strjoin(room[fd], buff);
		free(room[fd]);
		room[fd] = tmp;
		if (ft_strchr(room[fd], '\n'))
		{
			rt_n_store(&room[fd], line);
			rt = 1;
			break ;
		}
		else if (rt == 0)
			if (!(rt = rt_room(&room[fd], line)))
				break ;
	}
	return (rt);
}
