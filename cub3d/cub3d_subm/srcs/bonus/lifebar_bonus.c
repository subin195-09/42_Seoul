/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifebar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 14:41:54 by skim              #+#    #+#             */
/*   Updated: 2021/03/01 16:01:38 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	draw_bar(t_set *set, int x)
{
	int		i;
	int		j;

	i = -1;
	while (++i < LIFE_TILE)
	{
		j = -1;
		while (++j < LIFE_TILE)
			set->img.data[i * set->minfo.s_width + (j + x)] = 0xff0000;
	}
}

void	life_bar(t_set *set)
{
	int		i;
	int		x;

	i = -1;
	x = set->minfo.s_width / 3;
	while (++i < set->life.life)
	{
		x += 2;
		draw_bar(set, x);
	}
}
