/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 20:18:19 by skim              #+#    #+#             */
/*   Updated: 2021/02/28 17:08:31 by skim             ###   ########.fr       */
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
		if (set->map[w->map_x][w->map_y] == 1)
			return ;
	}
}

int		wall_set_tex_num(t_set *set, t_wcast *w)
{
	int		rt;

	w->line_height = (int)(set->minfo.s_height / w->perp_wall_dist);
	w->draw_start = (set->minfo.s_height / 2) - w->line_height / 2;
	w->draw_start = w->draw_start < 0 ? 0 : w->draw_start;
	w->draw_end = (set->minfo.s_height / 2) + w->line_height / 2;
	w->draw_end = w->draw_end >= set->minfo.s_height ? \
	set->minfo.s_height - 1 : w->draw_end;
	if (w->dir_side == 0)
		rt = w->ray_dir_x < 0 ? NO_TEXT_NUM : SO_TEXT_NUM;
	else
		rt = w->ray_dir_y < 0 ? WE_TEXT_NUM : EA_TEXT_NUM;
	return (rt);
}

void	wall_text(t_set *set, t_wcast *w, int x)
{
	t_text	t;
	double	wall_x;
	double	step;
	int		y;

	wall_x = w->dir_side == 0 ? set->info.pos_y + w->perp_wall_dist * \
	w->ray_dir_y : set->info.pos_x + w->perp_wall_dist * w->ray_dir_x;
	wall_x -= floor(wall_x);
	t.t_x = (int)(wall_x * (double)TEXTWIDTH);
	if (w->dir_side == 0 && w->ray_dir_x > 0)
		t.t_x = TEXTWIDTH - t.t_x - 1;
	if (w->dir_side == 1 && w->ray_dir_y < 0)
		t.t_x = TEXTWIDTH - t.t_x - 1;
	t.t_num = wall_set_tex_num(set, w);
	step = 1.0 * TEXTHEIGHT / w->line_height;
	t.t_pos = (w->draw_start - set->minfo.s_height / 2 + w->line_height / 2) * step;
	y = w->draw_start - 1;
	while (++y < w->draw_end)
	{
		t.t_y = (int)t.t_pos & (TEXTHEIGHT - 1);
		t.t_pos += step;
		t.color = set->info.texture[t.t_num][TEXTHEIGHT * t.t_y + t.t_x];
		set->img.data[y * set->minfo.s_width + x] = t.color;
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
