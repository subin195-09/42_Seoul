/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:03:34 by skim              #+#    #+#             */
/*   Updated: 2021/02/28 20:32:24 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

void	sprite_sort(t_scast *s, t_set *set)
{
	int		i;
	int		j;
	int		tmp;
	double	dis_tmp;
	double	max;

	i = -1;
	while (++i < set->minfo.num_sprite - 1)
	{
		max = s->sprite_distance[i];
		j = i;
		while (++j < set->minfo.num_sprite)
		{
			if (max <= s->sprite_distance[j])
			{
				max = s->sprite_distance[j];
				tmp = s->sprite_order[i];
				s->sprite_order[i] = s->sprite_order[j];
				s->sprite_order[j] = tmp;
				dis_tmp = s->sprite_distance[i];
				s->sprite_distance[i] = s->sprite_distance[j];
				s->sprite_distance[j] = dis_tmp;
			}
		}
	}
}

void	sprite_init(t_set *set, t_scast *s)
{
	int		i;

	i = -1;
	if (!(s->sprite_order = (int *)malloc(sizeof(int) * set->minfo.num_sprite)))
		return ;
	if (!(s->sprite_distance = \
	(double *)malloc(sizeof(double) * set->minfo.num_sprite)))
		return ;
	while (++i < set->minfo.num_sprite)
	{
		s->sprite_order[i] = i;
		s->sprite_distance[i] = \
		((set->info.pos_x - set->sprite[i].x) * \
		(set->info.pos_x - set->sprite[i].x)) + \
		((set->info.pos_y - set->sprite[i].y) * \
		(set->info.pos_y - set->sprite[i].y));
	}
	sprite_sort(s, set);
}

void	sprite_text_init(t_set *set, t_scast *s)
{
	s->draw_start_y = (set->minfo.s_height / 2) - s->sprite_height / 2;
	s->draw_end_y = (set->minfo.s_height / 2) + s->sprite_height / 2;
	s->draw_start_y = \
	s->draw_start_y < 0 ? 0 : s->draw_start_y;
	s->draw_end_y = s->draw_end_y >= set->minfo.s_height \
	? set->minfo.s_height - 1 : s->draw_end_y;
	s->sprite_width = (int)fabs(set->minfo.s_height / s->transform_y);
	s->draw_start_x = s->sprite_screen_x - s->sprite_width / 2;
	s->draw_end_x = s->sprite_screen_x + s->sprite_width / 2;
	s->draw_start_x = s->draw_start_x < 0 ? 0 : s->draw_start_x;
	s->draw_end_x = s->draw_end_x >= set->minfo.s_width ? \
	set->minfo.s_width - 1 : s->draw_end_x;
}

void	sprite_text(t_set *set, t_scast *s, int i)
{
	int		x;
	int		y;
	t_text	t;

	x = s->draw_start_x - 1;
	while (++x < s->draw_end_x)
	{
		t.t_x = (int)((256 * (x - (-s->sprite_width / 2 + s->sprite_screen_x)) \
		* TEXTWIDTH / s->sprite_width) / 256);
		if (s->transform_y > 0 && x > 0 && x < set->minfo.s_width \
		&& s->transform_y < set->info.z_buffer[x])
		{
			y = s->draw_start_y - 1;
			while (++y < s->draw_end_y)
			{
				t.t_y = ((y * 2 - set->minfo.s_height + s->sprite_height) \
				* 128 * TEXTHEIGHT) / s->sprite_height / 256;
				t.color = \
				set->info.texture[set->map[(int)set->sprite[s->sprite_order[i]].x][(int)set->sprite[s->sprite_order[i]].y] + 4][t.t_y * TEXTWIDTH + t.t_x];
				if ((t.color & 0X00FFFFFF) != 0)
					set->img.data[(y + set->up) * set->minfo.s_width + x] = \
					t.color;
			}
		}
	}
}

void	sprite_cast(t_set *set)
{
	t_scast	s;
	int		i;

	i = -1;
	sprite_init(set, &s);
	while (++i < set->minfo.num_sprite)
	{
		s.sprite_x = set->sprite[s.sprite_order[i]].x - set->info.pos_x;
		s.sprite_y = set->sprite[s.sprite_order[i]].y - set->info.pos_y;
		s.inv_dev = 1.0 / (set->info.plane_x * \
		set->info.dir_y - set->info.dir_x * set->info.plane_y);
		s.transform_x = s.inv_dev * \
		(set->info.dir_y * s.sprite_x - set->info.dir_x * s.sprite_y);
		s.transform_y = s.inv_dev * \
		(-set->info.plane_y * s.sprite_x + set->info.plane_x * s.sprite_y);
		s.sprite_screen_x = \
		(int)((set->minfo.s_width / 2) * (1 + s.transform_x / s.transform_y));
		s.sprite_height = (int)fabs(set->minfo.s_height / s.transform_y);
		sprite_text_init(set, &s);
		sprite_text(set, &s, i);
	}
}
