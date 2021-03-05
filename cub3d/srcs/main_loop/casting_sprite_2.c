/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_sprite_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skim <skim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:20:29 by skim              #+#    #+#             */
/*   Updated: 2021/03/05 17:32:15 by skim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub_main.h"

int		sprite_text_third(t_set *set, t_scast *s, t_text *t, int i)
{
	int		rt;

	rt = set->info.texture[set->map[(int)set->sprite\
	[s->sprite_order[i]].x][(int)set->sprite[s->sprite_order[i]].y]\
	+ 4][t->t_y * TEXTWIDTH + t->t_x];
	return (rt);
}

int		sprite_text_second(t_set *set, t_scast *s, t_text *t, int x)
{
	t->t_x = (int)((256 * (x - (-s->sprite_width / 2 + s->sprite_screen_x)) \
	* TEXTWIDTH / s->sprite_width) / 256);
	if (s->transform_y > 0 && x > 0 && x < set->minfo.s_width \
	&& s->transform_y < set->info.z_buffer[x])
		return (1);
	else
		return (0);
}

void	sprite_text(t_set *set, t_scast *s, int i)
{
	int		y;
	int		x;
	int		re_y;
	t_text	t;

	x = s->draw_start_x - 1;
	while (++x < s->draw_end_x)
	{
		if (sprite_text_second(set, s, &t, x))
		{
			y = s->draw_start_y - 1;
			while (++y < s->draw_end_y)
			{
				t.t_y = ((y * 2 - set->minfo.s_height + s->sprite_height) \
				* 128 * TEXTHEIGHT) / s->sprite_height / 256;
				re_y = y + set->up * 2 + set->jump + set->time_stamp;
				re_y = make_re_y(set, re_y);
				t.color = sprite_text_third(set, s, &t, i);
				if ((t.color & 0X00FFFFFF) != 0)
					set->img.data[re_y * set->minfo.s_width + x] = \
					make_darker(t.color, s->sprite_distance[i]);
			}
		}
	}
}
