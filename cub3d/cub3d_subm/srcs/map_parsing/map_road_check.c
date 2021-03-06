/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_road_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:28:12 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 18:52:46 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	sprite_count(t_set *set, int *a, int i, int j)
{
	set->sprite[*a].x = i - 1 + 0.5;
	set->sprite[*a].y = j - 1 + 0.5;
	(*a)++;
}

void	init_ck_map(t_set *set, int ***ck_map)
{
	int	i;
	int	j;
	int	a;

	i = -1;
	a = 0;
	if (!(set->sprite = \
	(t_sprite*)malloc(sizeof(t_sprite) * set->minfo.num_sprite)))
		return ;
	while (++i < set->minfo.m_height + 2)
	{
		j = -1;
		while (++j < set->minfo.m_width + 2)
		{
			if (i * j == 0 || \
			i == set->minfo.m_height + 1 || j == set->minfo.m_width + 1)
				(*ck_map)[i][j] = -1;
			else
			{
				(*ck_map)[i][j] = set->map[i - 1][j - 1];
				if (set->map[i - 1][j - 1] == 2 || set->map[i - 1][j - 1] == 3)
					sprite_count(set, &a, i, j);
			}
		}
	}
}

int		is_road(t_set *set, int ***ck_map, int x, int y)
{
	int		dir_x[4];
	int		dir_y[4];
	int		i;

	dir_x[0] = -1;
	dir_x[1] = 0;
	dir_x[2] = 1;
	dir_x[3] = 0;
	i = -1;
	while (++i < 4)
		dir_y[3 - i] = dir_x[i];
	i = -1;
	if ((*ck_map)[x][y] == 1 || (*ck_map)[x][y] == -2)
		return (1);
	if ((*ck_map)[x][y] == -1)
		return (0);
	(*ck_map)[x][y] = -2;
	i = -1;
	while (++i < 4)
		if (!is_road(set, ck_map, x + dir_x[i], y + dir_y[i]))
			return (0);
	return (1);
}

int		is_map(t_set *set, int **ck_map)
{
	int		is_zero;
	int		i;
	int		j;

	is_zero = 0;
	i = -1;
	while (++i < set->minfo.m_height)
	{
		j = -1;
		while (++j < set->minfo.m_width)
		{
			if (ck_map[i][j] == 0)
			{
				is_zero = 1;
				if (is_road(set, &ck_map, i, j) == 0)
					return (0);
			}
		}
	}
	if (!is_zero)
		return (0);
	else
		return (1);
}

int		check_map(t_set *set)
{
	int		**ck_map;
	int		i;
	int		rt;

	ck_map = (int **)malloc(sizeof(int *) * (set->minfo.m_height + 2));
	i = -1;
	while (++i < set->minfo.m_height + 2)
		ck_map[i] = (int *)malloc(sizeof(int) * (set->minfo.m_width + 2));
	init_ck_map(set, &ck_map);
	rt = is_map(set, ck_map);
	i = -1;
	while (++i < set->minfo.m_height + 2)
		free(ck_map[i]);
	free(ck_map);
	return (rt);
}
