/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:14:53 by skim              #+#    #+#             */
/*   Updated: 2021/02/28 20:28:00 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	draw_rect(t_set *set, int x, int y, int color)
{
	int i;
	int j;

	x *= MAP_TILE;
	y *= MAP_TILE;
	i = 0;
	while (i < MAP_TILE)
	{
		j = 0;
		while (j < MAP_TILE)
		{
			set->img.data[(x + i) * set->minfo.s_width + y + j] = color;
			j++;
		}
		i++;
	}
}

void	draw_all_rect(t_set *set)
{
	int i;
	int j;

	i = 0;
	while (i < set->minfo.m_height)
	{
		j = 0;
		while (j < set->minfo.m_width)
		{
			if (set->map[i][j] == 1)
				draw_rect(set, i, j, 0xffffff);
			else if (set->map[i][j] >= 2)
				draw_rect(set, i, j, 0xabcdef);
			j++;
		}
		i++;
	}
}

void	draw_map(t_set *set)
{
	int	i;
	int j;
	int	a;
	int	b;

	if (!set->key.key_sp)
		return ;
	draw_all_rect(set);
	i = set->info.pos_x * MAP_TILE;
	j = set->info.pos_y * MAP_TILE;
	a = -1;
	while (++a < 2)
	{
		b = -1;
		while (++b < 2)
			set->img.data[(i + a) * set->minfo.s_width + (j + b)] = 0xff0000;
	}
}
