/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 18:57:10 by skim              #+#    #+#             */
/*   Updated: 2020/10/12 22:24:22 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char		*result[OPEN_MAX];
	char			buffer[BUFFER_SIZE + 1];
	ssize_t			size;
	int				nl_index;

	// if (실패한 경우)
	// return (-1);
	while ((size = read(fd, buffer, BUFFER_SIZE) >= 0))
	{
		buffer[size] = '\0';
		result[fd] = ft_strjoin(result[fd], buffer);
		nl_index = check_nl(result[fd]);
		// 개행 문자가 있는 경우
		if (nl_index != 0)
		{
			split_nl(&result[fd], line);
			return (1);
		}
	}
	// 개행 문자가 없는 경우
	if (size >= 0)
	{
		line = &result[fd];
		return (0);
	}
	// 파일 읽기를 실패했을 경우
	else
		return (-1);
}
