/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:55:54 by skim              #+#    #+#             */
/*   Updated: 2021/03/03 19:17:04 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	floor_text(t_set *set, t_fcast f, int y, int re_y)
{
	t_text	t;
	int		x;

	x = -1;
	while (++x < set->minfo.s_width)
	{
		t.t_x = \
		(int)(TEXTWIDTH * (f.floor_x - (int)f.floor_x)) & (TEXTWIDTH - 1);
		t.t_y = \
		(int)(TEXTHEIGHT * (f.floor_y - (int)f.floor_y)) & (TEXTHEIGHT - 1);
		f.floor_x += f.floor_step_x;
		f.floor_y += f.floor_step_y;
		if (y <= re_y)
		{
			t.color = set->minfo.ceiling_text == 1 ? set->info.texture\
			[CE_TEXT_NUM][TEXTWIDTH * t.t_y + t.t_x] : set->minfo.ceiling;
		}
		else
		{
			t.color = set->minfo.floor_text == 1 ? set->info.texture\
			[FL_TEXT_NUM][TEXTWIDTH * t.t_y + t.t_x] : set->minfo.floor;
		}
		t.color = make_darker(t.color, set->minfo.s_height / 5 - abs(re_y - y));
		set->img.data[(y + set->jump) * set->minfo.s_width + x] = t.color;
	}
}

void	floor_cast(t_set *set)
{
	t_fcast	f;
	int		y;
	int		re_y;

	y = -1;
	while (++y < set->minfo.s_height)
	{
		f.ray_dir_x0 = set->info.dir_x - set->info.plane_x;
		f.ray_dir_y0 = set->info.dir_y - set->info.plane_y;
		f.ray_dir_x1 = set->info.dir_x + set->info.plane_x;
		f.ray_dir_y1 = set->info.dir_y + set->info.plane_y;
		make_re_y(set, y);
		re_y = set->minfo.s_height / 2 + set->up * 2;
		re_y = make_re_y(set, re_y);
		f.p = y - set->minfo.s_height / 2 - set->up * 2;
		f.p *= y < re_y ? -1 : 1;
		f.pos_z = 0.5 * set->minfo.s_height - set->up * 2;
		f.row_distance = f.pos_z / f.p;
		f.floor_x = set->info.pos_x + f.row_distance * f.ray_dir_x0;
		f.floor_y = set->info.pos_y + f.row_distance * f.ray_dir_y0;
		f.floor_step_x = f.row_distance * \
		(f.ray_dir_x1 - f.ray_dir_x0) / set->minfo.s_width;
		f.floor_step_y = f.row_distance * (\
		f.ray_dir_y1 - f.ray_dir_y0) / set->minfo.s_width;
		floor_text(set, f, y, re_y);
	}
}
