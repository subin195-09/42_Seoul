/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:57:10 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 19:18:30 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_restore(char **store, int *ret)
{
	char	*result;
	char	*temp;
	int		i;

	i = 0;
	if (ft_strchr(*store, '\n'))
	{
		while ((*store)[i] && ((*store)[i] != '\n'))
			i++;
		if (!(result = ft_strndup(*store, i)))
			return (0);
		if (!(temp = ft_strdup(*store + i + 1)))
			return (0);
		free(*store);
		*store = temp;
		*ret = 1;
	}
	else
	{
		result = ft_strdup(*store);
		free(*store);
		*store = 0;
		*ret = 0;
	}
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX + 1];
	char		*temp;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0 || !(line))
		return (-1);
	while (((ret = read(fd, buf, BUFFER_SIZE)) >= 0))
	{
		buf[ret] = 0;
		if (!(temp = store[fd] ? ft_strdup(store[fd]) : ft_strdup("")))
			return (-1);
		if (store[fd])
			free(store[fd]);
		if (!(store[fd] = ft_strjoin(temp, buf)))
			return (-1);
		free(temp);
		if (ft_strchr(store[fd], '\n') || ret == 0)
			break ;
	}
	if (ret == -1)
		return (-1);
	if (!(*line = ft_restore(&store[fd], &ret)))
		return (-1);
	return (ret);
}
