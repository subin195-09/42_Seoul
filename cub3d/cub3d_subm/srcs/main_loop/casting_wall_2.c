/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_wall_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:06:31 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 16:06:58 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		wall_set_tex_num(t_set *set, t_wcast *w)
{
	int		rt;

	w->line_height = (int)(set->minfo.s_height / w->perp_wall_dist);
	w->draw_start = (set->minfo.s_height / 2) - w->line_height / 2;
	w->draw_start = w->draw_start < 0 ? 0 : w->draw_start;
	w->draw_end = (set->minfo.s_height / 2) + w->line_height / 2;
	w->draw_end = w->draw_end >= set->minfo.s_height ? \
	set->minfo.s_height - 1 : w->draw_end;
	if (w->map_x == set->s_door.h_x && w->map_y == set->s_door.h_y)
		rt = SEC_TEXT_NUM;
	else if (w->dir_side == 0)
		rt = w->ray_dir_x < 0 ? NO_TEXT_NUM : SO_TEXT_NUM;
	else
		rt = w->ray_dir_y < 0 ? WE_TEXT_NUM : EA_TEXT_NUM;
	return (rt);
}

double	wall_text_init(t_set *set, t_wcast *w, t_text *t)
{
	double	wall_x;
	double	step;

	wall_x = w->dir_side == 0 ? set->info.pos_y + w->perp_wall_dist * \
	w->ray_dir_y : set->info.pos_x + w->perp_wall_dist * w->ray_dir_x;
	wall_x -= floor(wall_x);
	t->t_x = (int)(wall_x * (double)TEXTWIDTH);
	if (w->dir_side == 0 && w->ray_dir_x > 0)
		t->t_x = TEXTWIDTH - t->t_x - 1;
	if (w->dir_side == 1 && w->ray_dir_y < 0)
		t->t_x = TEXTWIDTH - t->t_x - 1;
	t->t_num = wall_set_tex_num(set, w);
	step = 1.0 * TEXTHEIGHT / w->line_height;
	t->t_pos = (w->draw_start - set->minfo.s_height / 2 \
	+ w->line_height / 2) * step;
	return (step);
}

void	wall_text(t_set *set, t_wcast *w, int x)
{
	t_text	t;
	double	step;
	int		y;
	int		re_y;

	step = wall_text_init(set, w, &t);
	y = w->draw_start - 1;
	while (++y < w->draw_end)
	{
		t.t_y = (int)t.t_pos & (TEXTHEIGHT - 1);
		t.t_pos += step;
		if (t.t_num == SEC_TEXT_NUM)
		{
			t.t_y -= set->s_door.h_text * 4;
			t.t_y = make_re_y(set, t.t_y);
			if (set->s_door.h_text == 32)
				set->map[set->s_door.h_x][set->s_door.h_y] = 0;
		}
		t.color = set->info.texture[t.t_num][TEXTHEIGHT * t.t_y + t.t_x];
		t.color = make_darker(t.color, set->minfo.s_height \
		/ 2 - w->line_height * 2);
		re_y = y + set->jump + (set->up * 2);
		re_y = make_re_y(set, re_y);
		set->img.data[re_y * set->minfo.s_width + x] = t.color;
	}
}
