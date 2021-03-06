/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_road.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:18:26 by skim              #+#    #+#             */
/*   Updated: 2021/03/06 17:39:20 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	set_s_door(t_set *set, int i, int j)
{
	set->s_door.h_x = i;
	set->s_door.h_y = j;
}

int		change_map(t_set *set, int **map, char *temp_map, int i)
{
	int		j;
	int		k;

	k = 0;
	j = -1;
	while (++j < set->minfo.m_width)
		(*map)[j] = -1;
	j = -1;
	while (temp_map[++j] != 0)
	{
		if (temp_map[j] == 'E' || temp_map[j] == 'W' || \
		temp_map[j] == 'S' || temp_map[j] == 'N')
		{
			set_pos(set, temp_map[j], i, j);
			temp_map[j] = '0';
			k = 1;
		}
		(*map)[j] = temp_map[j] == ' ' ? -1 : temp_map[j] - '0';
		if ((*map)[j] == 2 || (*map)[j] == 3)
			set->minfo.num_sprite++;
		if ((*map)[j] == 9)
			set_s_door(set, i, j);
	}
	return (k);
}

void	get_map_size(t_set *set, int fd, int fd_2, char **line)
{
	int		temp_size;

	set->minfo.m_height = 0;
	set->minfo.m_width = 0;
	temp_size = ft_strlen(*line);
	if (set->minfo.m_width < temp_size)
		set->minfo.m_width = temp_size;
	set->minfo.m_height++;
	write(fd_2, *line, temp_size);
	write(fd_2, "\n", 1);
	free(*line);
	while ((get_next_line(fd, line)) > 0)
	{
		temp_size = ft_strlen(*line);
		if (set->minfo.m_width < temp_size)
			set->minfo.m_width = temp_size;
		set->minfo.m_height++;
		write(fd_2, *line, temp_size);
		write(fd_2, "\n", 1);
		free(*line);
	}
}

void	map_malloc(t_set *set)
{
	int		i;

	i = -1;
	set->minfo.num_sprite = 0;
	set->map = (int **)malloc(sizeof(int *) * set->minfo.m_height);
	while (++i < set->minfo.m_height)
		set->map[i] = (int *)malloc(sizeof(int) * set->minfo.m_width);
}

int		get_map(int fd, char **line, t_set *set)
{
	int		i;
	int		fd_2;
	char	*temp_map;
	int		k;

	i = -1;
	k = 0;
	fd_2 = open("tmp_map", O_CREAT | O_RDWR | O_TRUNC, 0777);
	get_map_size(set, fd, fd_2, line);
	map_malloc(set);
	close(fd);
	close(fd_2);
	fd_2 = open("tmp_map", O_RDONLY);
	i = 0;
	while ((get_next_line(fd_2, &temp_map) > 0))
	{
		k += change_map(set, &(set->map[i]), temp_map, i);
		i++;
		free(temp_map);
	}
	if (k != 1)
		cub3d_exit(set, error_msg("no pos!\n"));
	free(temp_map);
	close(fd_2);
	return (1);
}
