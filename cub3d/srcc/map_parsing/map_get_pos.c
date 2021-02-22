/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_get_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:27:26 by skim              #+#    #+#             */
/*   Updated: 2021/02/22 23:27:46 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	set_dir(t_set *set, int d_x, int d_y)
{
	set->info.dir_x = d_x;
	set->info.dir_y = d_y;
}

void	set_plane(t_set *set, int p_x, int p_y)
{
	set->info.plane_x = p_x;
	set->info.plane_y = p_y;
}

void	set_pos(t_set *set, char pos)
{
	if (pos == 'E')
	{
		set_dir(set, 0, 1);
		set_plane(set, 0.66, 0);
	}
	if (pos == 'W')
	{
		set_dir(set, 0, -1);
		set_plane(set, -0.66, 0);
	}
	if (pos == 'S')
	{
		set_dir(set, 1, 0);
		set_plane(set, 0, -0.66);
	}
	if (pos == 'N')
	{
		set_dir(set, -1, 0);
		set_plane(set, 0, 0.66);
	}
}
