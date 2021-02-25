/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:53:43 by skim              #+#    #+#             */
/*   Updated: 2021/02/25 22:50:06 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		map_name_check(char *map_name)
{
	int		i;

	i = ft_strlen(map_name);
	if (ft_strncmp(map_name + i - 4, ".cub", 4))
		return (0);
	return (1);
}

int		map_parse(t_set *set, char *map_name)
{
	char			*line;
	int				fd;
	unsigned char	flag;
	int				i;

	fd = open(map_name, O_RDONLY);
	flag = 0;
	i = 0;
	if (!map_name_check(map_name))
		return (error_msg("map name error"));
	if (!map_check(set, fd, &line))
		return (0);
	while (line[0] != ' ' && !ft_isdigit(line[0]))
		get_next_line(fd, &line);
	get_map(fd, &line, set);
	if (!check_map(set))
		return (error_msg("wrong map"));
	return (1);
}
