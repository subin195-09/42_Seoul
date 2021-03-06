/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:18:19 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 16:06:54 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	wall_side(t_set *set, t_wcast *w)
{
	if (w->ray_dir_x < 0)
	{
		w->step_x = -1;
		w->side_dist_x = (set->info.pos_x - w->map_x) * w->delta_dist_x;
	}
	else
	{
		w->step_x = 1;
		w->side_dist_x = (w->map_x + 1.0 - set->info.pos_x) * w->delta_dist_x;
	}
	if (w->ray_dir_y < 0)
	{
		w->step_y = -1;
		w->side_dist_y = (set->info.pos_y - w->map_y) * w->delta_dist_y;
	}
	else
	{
		w->step_y = 1;
		w->side_dist_y = (w->map_y + 1.0 - set->info.pos_y) * w->delta_dist_y;
	}
}

void	wall_hit(t_set *set, t_wcast *w)
{
	while (1)
	{
		if (w->side_dist_x < w->side_dist_y)
		{
			w->side_dist_x += w->delta_dist_x;
			w->map_x += w->step_x;
			w->dir_side = 0;
		}
		else
		{
			w->side_dist_y += w->delta_dist_y;
			w->map_y += w->step_y;
			w->dir_side = 1;
		}
		if (set->map[w->map_x][w->map_y] == 1 || \
		(w->map_x == set->s_door.h_x && w->map_y == \
		set->s_door.h_y && set->s_door.h_text != 32))
		{
			if (w->map_x == set->s_door.h_x && w->map_y == set->s_door.h_y)
				set->s_door.is_hidden = 1;
			return ;
		}
	}
}

void	wall_cast(t_set *set)
{
	t_wcast	w;
	int		x;

	x = -1;
	while (++x < set->minfo.s_width)
	{
		w.camera_x = 2 * x / (1.0 * set->minfo.s_width) - 1;
		w.ray_dir_x = set->info.dir_x + set->info.plane_x * w.camera_x;
		w.ray_dir_y = set->info.dir_y + set->info.plane_y * w.camera_x;
		w.map_x = (int)set->info.pos_x;
		w.map_y = (int)set->info.pos_y;
		w.delta_dist_x = fabs(1 / w.ray_dir_x);
		w.delta_dist_y = fabs(1 / w.ray_dir_y);
		wall_side(set, &w);
		wall_hit(set, &w);
		if (w.dir_side == 0)
			w.perp_wall_dist = \
			(w.map_x - set->info.pos_x + (1 - w.step_x) / 2) / w.ray_dir_x;
		else
			w.perp_wall_dist = \
			(w.map_y - set->info.pos_y + (1 - w.step_y) / 2) / w.ray_dir_y;
		wall_text(set, &w, x);
		set->info.z_buffer[x] = w.perp_wall_dist;
	}
}
