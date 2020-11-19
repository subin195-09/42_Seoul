/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:57:10 by skim              #+#    #+#             */
/*   Updated: 2020/11/20 01:55:36 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_restore(char **store, int ret)
{
	char	*result;
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	while ((*store)[i] && ((*store)[i] != '\n'))
		i++;
	if (!(result = malloc(i + 1)))
		return (0);
	if (!(temp = malloc(strlen((*store) - i))))
		return (0);
	result[i] = 0;
	while(++j < i)
		result[j] = (*store)[j];
	i = 0;
	while ((*store)[++j])
		temp[i++] = (*store)[j];
	free(*store);
	(*store) = strdup(temp);
	free(temp);
	return (result);
}

int		get_next_line(int fd, char **line)
{
	static char	*store[OPEN_MAX];
	char		*temp_one;
	char		*temp_two;
	int			flag;
	int			ret;

	flag = 0;
	while (!flag || (!(ft_strchr(store[fd], '\n')) && ret > 0))
	{
		flag = 1;
		if (!(temp_two = malloc(BUFFER_SIZE)))
			return (-1);
		ret = read(fd, temp_two, BUFFER_SIZE);
		temp_one = store[fd] ? ft_strdup(store[fd]) : ft_strdup("");
		free(store[fd]);
		store[fd] = flag == 0 ? ft_strjoin(temp_two, temp_one) : ft_strjoin(temp_one, temp_two);
		free(temp_one);
		free(temp_two);
		flag = 1;
	}
	*line = ft_restore(&store[fd], ret);
	return (ret > 0 ? 1 : 0);
}
